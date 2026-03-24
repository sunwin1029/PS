#include <bits/stdc++.h>
using namespace std;

vector <vector <int>> board;
vector <vector <int>> tmpDefuseBoard;
int drow[4] = {1, -1, 0, 0};
int dcol[4] = {0, 0, -1, 1};
int r, c, t;

int upAirRightRow = 0;
int downAirRightRow = 0;

void defuseStore(int row, int col) {
    if(board[row][col] == -1) return;

    int defuseAmt = 0;

    for(int i = 0; i < 4; i++) {
        int newRow = row + drow[i];
        int newCol = col + dcol[i];

        if(newRow < 0 || newRow >= r || newCol < 0 || newCol >= c) {
            continue;
        }
        if(board[newRow][newCol] == -1) continue;

        defuseAmt++;
    }

    int defuseVal = board[row][col] / 5;

    for(int i = 0; i < 4; i++) {
        int newRow = row + drow[i];
        int newCol = col + dcol[i];

        if(newRow < 0 || newRow >= r || newCol < 0 || newCol >= c) {
            continue;
        }
        if(board[newRow][newCol] == -1) continue;

        tmpDefuseBoard[row][col] -= defuseVal;
        tmpDefuseBoard[newRow][newCol] += defuseVal;
    }
}

void defuseProcess() {
    // 초기화
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            tmpDefuseBoard[i][j] = 0;
        }
    }

    // 확산 과정
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            defuseStore(i, j);
        }
    }

    //확산 처리
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            board[i][j] += tmpDefuseBoard[i][j];
        }
    }
}

void airConditionalMove() {
    // 0열 아래로
    for(int i = upAirRightRow - 1; i > 0; i--) {
        board[i][0] = board[i - 1][0];
    }
    // 0행 왼쪽으로
    for(int i = 0; i < c - 1; i++) {
        board[0][i] = board[0][i + 1];
    }
    // c - 1행 위쪽으로
    for(int i = 0; i < upAirRightRow; i++) {
        board[i][c - 1] = board[i + 1][c - 1];
    }
    // upAirRightRow에서 오른쪽으로
    for(int i = c - 1; i > 0; i--) {
        if(i == 1) {
            board[upAirRightRow][1] = 0;
            continue;
        } 
        board[upAirRightRow][i] = board[upAirRightRow][i - 1];
    }

    // 0열 위로
    for(int i = downAirRightRow + 1; i < r - 1; i++) {
        board[i][0] = board[i + 1][0];
    }
    // r - 1행 왼쪽으로
    for(int i = 0; i < c - 1; i++) {
        board[r - 1][i] = board[r - 1][i + 1];
    }
    // c열 아래쪽으로
    for(int i = r - 1; i > downAirRightRow; i--) {
        board[i][c - 1] = board[i - 1][c - 1];
    }
    // downAirRightRow에서 오른쪽으로
    for(int i = c - 1; i > 0; i--) {
        if(i == 1) {
            board[downAirRightRow][1] = 0;
            continue;
        }
        board[downAirRightRow][i] = board[downAirRightRow][i - 1];
    }
}

void printRes() {
    int res = 0;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(board[i][j] == -1) continue;

            res += board[i][j];
        }
    }

    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c >> t;

    board.resize(r, vector<int>(c));
    tmpDefuseBoard.resize(r, vector<int>(c));
    
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> board[i][j];

            if(board[i][j] == -1) {
                if(upAirRightRow == 0) {
                    upAirRightRow = i;
                }
                else {
                    downAirRightRow = i;
                }
            }
        }
    }

    while(t--) {
        defuseProcess();
        airConditionalMove();
    }

    printRes();


    return 0;
}