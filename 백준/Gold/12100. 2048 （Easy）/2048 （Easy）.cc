#include <bits/stdc++.h>
#define TYPE vector<vector<int>>
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
using namespace std;

vector<vector<int>> originBoard;
int n;

void moveUp(TYPE& board) {
    for(int col = 0; col < n; col++) {
        int canCombineIndex = 0;  // 합쳐질 수 있는 공간, 중복 합체를 막기 위함

        for(int row = 1; row < n; row++) {
            if(board[row][col] == 0) continue;  // 빈공간

            // 합쳐질 수 있는 경우
            if(board[row][col] == board[canCombineIndex][col]) {
                board[canCombineIndex][col] *= 2;
                board[row][col] = 0;
                canCombineIndex++;
            }
            // 합쳐질 수 없는 경우 그냥 위로 이동
            else {
                int tmp = board[row][col];
                board[row][col] = 0;
                if(board[canCombineIndex][col] != 0) {
                    canCombineIndex++;
                }
                board[canCombineIndex][col] = tmp;
            }
        }
    }
}

void moveDown(TYPE& board) {
    for(int col = 0; col < n; col++) {
        int canCombineIndex =
            n - 1;  // 합쳐질 수 있는 공간, 중복 합체를 막기 위함
        for(int row = n - 2; row >= 0; row--) {
            if(board[row][col] == 0) continue;  // 빈공간

            // 합쳐질 수 있는 경우
            if(board[row][col] == board[canCombineIndex][col]) {
                board[canCombineIndex][col] *= 2;
                board[row][col] = 0;
                canCombineIndex--;
            }
            // 합쳐질 수 없는 경우 그냥 아래로 이동
            else {
                int tmp = board[row][col];
                board[row][col] = 0;

                if(board[canCombineIndex][col] != 0) {
                    canCombineIndex--;
                }
                board[canCombineIndex][col] = tmp;
            }
        }
    }
}

void moveLeft(TYPE& board) {
    for(int row = 0; row < n; row++) {
        int canCombineIndex = 0;  // 합쳐질 수 있는 공간, 중복 합체를 막기 위함
        for(int col = 1; col < n; col++) {
            if(board[row][col] == 0) continue;  // 빈공간

            // 합쳐질 수 있는 경우
            if(board[row][col] == board[row][canCombineIndex]) {
                board[row][canCombineIndex] *= 2;
                board[row][col] = 0;
                canCombineIndex++;
            }
            // 합쳐질 수 없는 경우 그냥 왼쪽으로 이동
            else {
                int tmp = board[row][col];
                board[row][col] = 0;

                if(board[row][canCombineIndex] != 0) {
                    canCombineIndex++;
                }
                board[row][canCombineIndex] = tmp;
            }
            // canCombineIndex++;  // 다음 합쳐질 수 있는 위치 확인
        }
    }
}

void moveRight(TYPE& board) {
    for(int row = 0; row < n; row++) {
        int canCombineIndex =
            n - 1;  // 합쳐질 수 있는 공간, 중복 합체를 막기 위함
        for(int col = n - 2; col >= 0; col--) {
            if(board[row][col] == 0) continue;  // 빈공간

            // 합쳐질 수 있는 경우
            if(board[row][col] == board[row][canCombineIndex]) {
                board[row][canCombineIndex] *= 2;
                board[row][col] = 0;
                canCombineIndex--;
            }
            // 합쳐질 수 없는 경우 그냥 오른쪽으로 이동
            else {
                int tmp = board[row][col];
                board[row][col] = 0;

                if(board[row][canCombineIndex] != 0) {
                    canCombineIndex--;
                }

                board[row][canCombineIndex] = tmp;
            }
        }
    }
}

int getMaximum(TYPE& board) {
    int res = INT_MIN;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            res = max(res, board[i][j]);
        }
    }

    return res;
}

int program(int state) {
    TYPE tmp;
    tmp.resize(n, vector<int>(n));

    tmp = originBoard;

    for(int i = 0; i < 5; i++) {
        int cmd = (state >> (2 * i)) & 3;

        switch(cmd) {
            case UP:
                moveUp(tmp);
                break;
            case DOWN:
                moveDown(tmp);
                break;
            case LEFT:
                moveLeft(tmp);
                break;
            case RIGHT:
                moveRight(tmp);
                break;
        }
    }
    return getMaximum(tmp);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    originBoard.resize(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> originBoard[i][j];
        }
    }

    int res = INT_MIN;

    for(int state = 0; state < (1 << 10); state++) {
        res = max(res, program(state));
    }

    cout << res << "\n";

    return 0;
}
