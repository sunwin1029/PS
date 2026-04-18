#include <bits/stdc++.h>
#define EMPTY 0
#define SHARK -1

using namespace std;

int m, s;
int drow[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dcol[8] = {-1, -1, 0, 1, 1, 1, 0, -1};  // 0-index
int dsharkRow[4] = {-1, 0, 1, 0};           // 상, 좌, 하, 우
int dsharkCol[4] = {0, -1, 0, 1};

int sharkRow;
int sharkCol;

vector<vector<vector<int>>> board(5, vector<vector<int>>(5));
vector<vector<int>> smell(5, vector<int>(5));

// 물고기가 담아야 하는 정보
// 1. 방향
// 2. 냄새

bool rangeCheck(int row, int col) {
    if(row < 1 || row > 4 || col < 1 || col > 4) return false;
    return true;
}

void fishMove() {
    vector<vector<vector<int>>> nextBoard(5, vector<vector<int>>(5));

    for(int r = 1; r <= 4; r++) {
        for(int c = 1; c <= 4; c++) {
            for(int amt = 0; amt < board[r][c].size(); amt++) {
                int dir = board[r][c][amt];
                int originDir = dir;
                int fishRow;
                int fishCol;
                bool movePossible = false;

                for(int i = 0; i < 8; i++) {
                    fishRow = r + drow[dir];
                    fishCol = c + dcol[dir];

                    // 격자의 범위를 벗어나는 칸
                    if(fishRow < 1 || fishRow > 4 || fishCol < 1 ||
                       fishCol > 4) {
                        dir = (dir + 7) % 8;
                        continue;
                    }
                    // 상어가 있는칸
                    if(fishRow == sharkRow && fishCol == sharkCol) {
                        dir = (dir + 7) % 8;
                        continue;
                    }

                    // 냄새가 존재하는 칸
                    if(smell[fishRow][fishCol] > 0) {
                        dir = (dir + 7) % 8;
                        continue;
                    }

                    nextBoard[fishRow][fishCol].push_back(dir);
                    movePossible = true;
                    break;
                }
                if(!movePossible) {
                    dir = originDir;  // 원 방향으로 복귀
                    nextBoard[r][c].push_back(dir);
                }
            }
        }
    }
    board = nextBoard;
}

void sharkMove() {
    int bestMoveFishAmt = -1;
    vector<int> bestMove(3);

    // 최선의 선택 찾기
    for(int firstDir = 0; firstDir < 4; firstDir++) {
        for(int secondDir = 0; secondDir < 4; secondDir++) {
            for(int thirdDir = 0; thirdDir < 4; thirdDir++) {
                vector<vector<bool>> visited(5, vector<bool>(5, false));

                int fishAmt = 0;

                int tmpRow = sharkRow;
                int tmpCol = sharkCol;

                // 첫번재 움직임
                tmpRow = tmpRow + dsharkRow[firstDir];
                tmpCol = tmpCol + dsharkCol[firstDir];
                if(!rangeCheck(tmpRow, tmpCol)) continue;
                fishAmt += board[tmpRow][tmpCol].size();
                visited[tmpRow][tmpCol] = true;

                // 두번재 움직임
                tmpRow = tmpRow + dsharkRow[secondDir];
                tmpCol = tmpCol + dsharkCol[secondDir];
                if(!rangeCheck(tmpRow, tmpCol)) continue;
                if(!visited[tmpRow][tmpCol])
                    fishAmt += board[tmpRow][tmpCol].size();
                visited[tmpRow][tmpCol] = true;

                // 세번째 움직임
                tmpRow = tmpRow + dsharkRow[thirdDir];
                tmpCol = tmpCol + dsharkCol[thirdDir];
                if(!rangeCheck(tmpRow, tmpCol)) continue;
                if(!visited[tmpRow][tmpCol])
                    fishAmt += board[tmpRow][tmpCol].size();

                if(fishAmt > bestMoveFishAmt) {
                    bestMoveFishAmt = fishAmt;
                    bestMove[0] = firstDir;
                    bestMove[1] = secondDir;
                    bestMove[2] = thirdDir;
                }
            }
        }
    }

    vector<vector<bool>> isVisited(5, vector<bool>(5, false));

    // 실제 상어 이동시키기
    for(int i = 0; i < 3; i++) {
        sharkRow = sharkRow + dsharkRow[bestMove[i]];
        sharkCol = sharkCol + dsharkCol[bestMove[i]];

        if(board[sharkRow][sharkCol].size() > 0 &&
           !isVisited[sharkRow][sharkCol]) {
            board[sharkRow][sharkCol] = vector<int>(0);
            smell[sharkRow][sharkCol] = 3;
        }

        isVisited[sharkRow][sharkCol] = true;
    }
}

void decreaseSmell() {
    for(int r = 1; r <= 4; r++) {
        for(int c = 1; c <= 4; c++) {
            if(smell[r][c] > 0) {
                smell[r][c]--;
            }
        }
    }
}

int getTotalFish() {
    int res = 0;
    for(int r = 1; r <= 4; r++) {
        for(int c = 1; c <= 4; c++) {
            res += board[r][c].size();
        }
    }

    return res;
}

void program() {
    vector<vector<vector<int>>> copyBoard(5, vector<vector<int>>(5));
    copyBoard = board;

    fishMove();
    sharkMove();
    decreaseSmell();

    for(int r = 1; r <= 4; r++) {
        for(int c = 1; c <= 4; c++) {
            for(int i = 0; i < copyBoard[r][c].size(); i++) {
                board[r][c].push_back(copyBoard[r][c][i]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> s;

    for(int i = 0; i < m; i++) {
        int x, y, d;
        cin >> x >> y >> d;
        board[x][y].push_back(d - 1);
    }

    cin >> sharkRow >> sharkCol;

    while(s--) {
        program();
    }

    cout << getTotalFish() << "\n";

    return 0;
}