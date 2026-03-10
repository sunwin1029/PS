#include <bits/stdc++.h>
#define TYPE pair<int, int>
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
using namespace std;

int drow[4] = {-1, 1, 0, 0};  // 상하좌우
int dcol[4] = {0, 0, -1, 1};  // 상하좌우

vector<vector<char>> board;
bool visited[11][11][11][11];
TYPE redBall;
TYPE blueBall;
int res = INT_MAX;

void mark(TYPE r, TYPE b) {
    visited[r.first][r.second][b.first][b.second] = true;
}

// return value
// true : reach endPoint
// false : reach at none endPoint
bool moveRed(int direction, TYPE otherBall) {
    bool moveCompleted = false;

    int newRow = redBall.first;
    int newCol = redBall.second;


    while(!moveCompleted) {
        newRow = newRow + drow[direction];
        newCol = newCol + dcol[direction];

        if(TYPE{newRow, newCol} == otherBall) {
            newRow -= drow[direction];
            newCol -= dcol[direction];
            redBall = {newRow, newCol};
            return false;
        }

        if(board[newRow][newCol] == 'O') return true;
        if(board[newRow][newCol] == '.')
            continue;
        else {
            newRow = newRow - drow[direction];
            newCol = newCol - dcol[direction];
            redBall = {newRow, newCol};
            return false;
        }
    }
}

// return true if not failure
// return false when ball in hole
bool moveBlue(int direction, TYPE otherBall) {
    bool moveCompleted = false;

    int newRow = blueBall.first;
    int newCol = blueBall.second;


    while(!moveCompleted) {
        newRow = newRow + drow[direction];
        newCol = newCol + dcol[direction];

        if(TYPE{newRow, newCol} == otherBall) {
            newRow -= drow[direction];
            newCol -= dcol[direction];
            blueBall = {newRow, newCol};
            return true;
        }

        if(board[newRow][newCol] == 'O') return false;  // 원상복귀 시켜야함
        if(board[newRow][newCol] == '.')
            continue;
        else {
            newRow = newRow - drow[direction];
            newCol = newCol - dcol[direction];
            blueBall = {newRow, newCol};
            return true;
        }
    }
}

// 공 2개를 이동시켜주는 함수
// moveProcess(true, ) 빨간공 먼저, moveProcess(false, ) = 파란공 먼저
void moveProcess(bool b, int direction, int tmpMove,
                 queue<tuple<TYPE, TYPE, int>>& q) {
    TYPE oldR = redBall;
    TYPE oldB = blueBall;
    TYPE no_block = {-1, -1};

    // 빨간공 먼저
    if(b) {
        // 빨간공 들어감
        if(moveRed(direction, no_block)) {
            if(moveBlue(direction, no_block)) res = min(res, tmpMove + 1);
        }
        // 빨간공 안들어감
        else {
            // 파란공 구멍에 안들어가면
            if(moveBlue(direction, redBall)) {
                if(!visited[redBall.first][redBall.second][blueBall.first]
                           [blueBall.second]) {
                    q.push({redBall, blueBall, tmpMove + 1});
                    mark(redBall, blueBall);  // 마킹
                }
            }
        }
        blueBall = oldB;
        redBall = oldR;  // 원위치
    }
    // 파란공 먼저
    else {
        // 파란공 구멍에 안들어가면
        if(moveBlue(direction, no_block)) {
            // 빨간공 들어감
            if(moveRed(direction, blueBall)) {
                res = min(res, tmpMove + 1);
            }
            // 빨간공 안들어감
            else {
                if(!visited[redBall.first][redBall.second][blueBall.first]
                           [blueBall.second]) {
                    q.push({redBall, blueBall, tmpMove + 1});
                    mark(redBall, blueBall);  // 마킹
                }
            }
            redBall = oldR;  // 원위치
        }
        blueBall = oldB;  // 원위치
    }
}

void bfs(TYPE rStart, TYPE bStart) {
    queue<tuple<TYPE, TYPE, int>> q;  // {redBall, blueBall, movementAmt}

    mark(rStart, bStart);
    q.push({rStart, bStart, 0});

    while(!q.empty()) {
        tuple<TYPE, TYPE, int> curPos = q.front();
        redBall = get<0>(curPos);
        blueBall = get<1>(curPos);
        int tmpMove = get<2>(curPos);
        q.pop();


        for(int i = 0; i < 4; i++) {
            bool order;
            // 공의 이동 순서 판단
            switch(i) {
                case UP:
                    order = (blueBall.first < redBall.first) ? false : true;
                    break;
                case DOWN:
                    order = (blueBall.first > redBall.first) ? false : true;
                    break;
                case LEFT:
                    order = (blueBall.second < redBall.second) ? false : true;
                    break;
                case RIGHT:
                    order = (blueBall.second > redBall.second) ? false : true;
                    break;
            }
            moveProcess(order, i, tmpMove, q);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int row, column;
    TYPE rStart;
    TYPE bStart;
    cin >> row >> column;

    board.resize(row, vector<char>(column));

    for(int i = 0; i < row; i++) {
        string s;
        cin >> s;

        for(int j = 0; j < column; j++) {
            board[i][j] = s[j];
            if(board[i][j] == 'R') {
                rStart = {i, j};
                board[i][j] = '.';
            } else if(board[i][j] == 'B') {
                bStart = {i, j};
                board[i][j] = '.';
            }
        }
    }

    bfs(rStart, bStart);


    cout << ((res == INT_MAX) || res > 10 ? -1 : res) << "\n";

    return 0;
}