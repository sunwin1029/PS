#include <bits/stdc++.h>
#define SHARK -2
#define EMPTY -1
using namespace std;

int drow[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dcol[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int res = 0;

void fishMove(vector<pair<int, int>>& fish,
              vector<vector<pair<int, int>>>& board, pair<int, int> sharkLoc);

int backTracking(int score, vector<pair<int, int>> fish,
                 vector<vector<pair<int, int>>> board, pair<int, int> sharkLoc,
                 int sharkDir) {
    fishMove(fish, board, sharkLoc);

    bool sharkMovePossible = false;  // 상어 이동 가능한지 확인

    int res = score;

    // 상어가 이동할 수 있는 최대 범위는 3칸임
    for(int i = 1; i < 4; i++) {
        // 상어가 이동할 위치 계산
        int newRow = sharkLoc.first + drow[sharkDir] * i;
        int newCol = sharkLoc.second + dcol[sharkDir] * i;

        // 상어가 범위를 벗어나는 경우, 더이상 이동 불가능
        if(newRow < 0 || newRow >= 4 || newCol < 0 || newCol >= 4) break;

        // 이동한 칸이 비어있는 경우
        if(board[newRow][newCol].first == EMPTY) {
            continue;
        }

        // 상어가 이번 턴에 움직일 수 있음
        sharkMovePossible = true;

        // 백트래킹을 하기 위한 값
        vector<pair<int, int>> tmpFish = fish;
        vector<vector<pair<int, int>>> tmpBoard = board;
        int tmpScore = score;
        int tmpDir;

        // 상어의 이동
        tmpScore += tmpBoard[newRow][newCol].first;  // 점수추가
        tmpDir = tmpBoard[newRow][newCol].second;    // 방향 변경
        tmpFish[tmpBoard[newRow][newCol].first] = {
            EMPTY, EMPTY};  // 기존 위치의 값은 지우기
        tmpBoard[newRow][newCol] = {EMPTY, EMPTY};

        res = max(res, backTracking(tmpScore, tmpFish, tmpBoard, {newRow, newCol}, tmpDir));
    }

    return res;
}

void fishMove(vector<pair<int, int>>& fish,
              vector<vector<pair<int, int>>>& board, pair<int, int> sharkLoc) {
    // i = 물고기 번호
    for(int i = 1; i <= 16; i++) {
        // 이미 사라진 물고기
        if(fish[i].first < 0) continue;

        int row = fish[i].first;
        int col = fish[i].second;
        int newRow, newCol;  // 이동할 위치
        pair<int, int> tmpFish =
            board[row][col];  // 물고기 이동시 임시 저장 공간
        int changedFishNum;   // 이동할 위치의 물고기 번호

        int tmpDir = tmpFish.second;  // 방향 지정
        int j;
        for(j = 0; j < 8; j++) {
            newRow = row + drow[(tmpDir + j) % 8];
            newCol = col + dcol[(tmpDir + j) % 8];

            // 공간의 경계를 넘는칸
            if(newRow < 0 || newRow > 3 || newCol < 0 || newCol > 3) {
                continue;
            }
            // 상어가 있는칸
            if(newRow == sharkLoc.first && newCol == sharkLoc.second) {
                continue;
            }

            break;
        }

        tmpFish = {board[row][col].first, (tmpDir + j) % 8};

        // 물고기 이동 불가능
        if(j >= 8) continue;

        // 물고기가 이동할 칸이 빈칸인 경우
        if(board[newRow][newCol].first == EMPTY) {
            board[newRow][newCol] = tmpFish;
            board[row][col] = {EMPTY, EMPTY};
            fish[i] = {newRow, newCol};
        }
        // 물고기가 있는 경우
        else {
            board[row][col] = board[newRow][newCol];
            changedFishNum = board[newRow][newCol].first;
            fish[changedFishNum] = {row, col};


            board[newRow][newCol] = tmpFish;
            fish[i] = {newRow, newCol};
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<int, int>> fish(17);  // n번 물고기가 어디에 있는가?
    vector<vector<pair<int, int>>> board(
        4, vector<pair<int, int>>(4));  // 번호와 방향
    pair<int, int> sharkLoc;            // 상어의 위치
    int sharkDir;
    int score;
    int res = 0;

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            int a, b;
            cin >> a >> b;
            b--;

            // 물고기 위치 저장
            fish[a] = {i, j};

            board[i][j] = {a, b};
        }
    }

    // 0번 위치의 물고기 먹기
    score = board[0][0].first;
    sharkDir = board[0][0].second;
    sharkLoc = {0, 0};

    // 물고기 없애기
    fish[board[0][0].first] = {EMPTY, EMPTY};
    board[0][0] = {EMPTY, EMPTY};

    res = backTracking(score, fish, board, sharkLoc, sharkDir);

    cout << res << "\n";

    return 0;
}