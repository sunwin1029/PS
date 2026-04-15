#include <bits/stdc++.h>
#define UP 0
#define DOWN 2
#define LEFT 3
#define RIGHT 1
using namespace std;

int n, m, k;
vector<vector<int>> board;
// 주사위의 위치
int r = 1;
int c = 1;
int total = 0;

int drow[4] = {-1, 0, 1, 0};  // {상, 우, 하, 좌}
int dcol[4] = {0, 1, 0, -1};
int dir = 1;

// 주사위의 상태
struct Dice {
    int bottom = 6;
    int east = 3;
    int south = 5;
    int top = 1;
    int west = 4;
    int north = 2;
};

Dice dice;

// 함수 프로토타입

void roll();
void process();
int bfs();

void roll() {
    Dice tmp = dice;

    if(dir == UP) {
        dice.bottom = tmp.north;
        dice.south = tmp.bottom;
        dice.top = tmp.south;
        dice.north = tmp.top;
    }
    if(dir == DOWN) {
        dice.bottom = tmp.south;
        dice.south = tmp.top;
        dice.top = tmp.north;
        dice.north = tmp.bottom;
    }
    if(dir == LEFT) {
        dice.bottom = tmp.west;
        dice.west = tmp.top;
        dice.top = tmp.east;
        dice.east = tmp.bottom;
    }
    if(dir == RIGHT) {
        dice.bottom = tmp.east;
        dice.east = tmp.top;
        dice.top = tmp.west;
        dice.west = tmp.bottom;
    }
}

void process() {
    int newRow = r + drow[dir];
    int newCol = c + dcol[dir];

    // 굴러가기
    if(newRow > n || newRow < 1) {
        dir = (dir + 2) % 4;  // 방향 반대로
        newRow = r + drow[dir];
    }
    if(newCol > m || newCol < 1) {
        dir = (dir + 2) % 4;
        newCol = c + dcol[dir];
    }

    roll();
    r = newRow;
    c = newCol;

    total += board[r][c] * bfs();

    if(dice.bottom > board[r][c]) {
        dir = (dir + 1) % 4;
    } else if(dice.bottom < board[r][c]) {
        dir = (dir + 3) % 4;
    }
}

int bfs() {
    queue<pair<int, int>> q;
    vector<vector<bool>> checkBoard(n + 1, vector<bool>(m + 1));

    q.push({r, c});
    int locNum = board[r][c];
    int amt = 0;
    checkBoard[r][c] = true;

    while(!q.empty()) {
        pair<int, int> tmp = q.front();
        q.pop();
        amt++;

        for(int i = 0; i < 4; i++) {
            int newRow = tmp.first + drow[i];
            int newCol = tmp.second + dcol[i];

            if(newRow < 1 || newRow > n || newCol < 1 || newCol > m) {
                continue;
            }

            // 숫자가 같지 않은 경우, 이미 방문한 곳인 경우
            if(board[newRow][newCol] != locNum || checkBoard[newRow][newCol])
                continue;

            q.push({newRow, newCol});
            checkBoard[newRow][newCol] = true;
        }
    }


    return amt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    board.resize(n + 1, vector<int>(m + 1));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> board[i][j];
        }
    }

    while(k--) {
        process();
    }

    cout << total << "\n";

    return 0;
}