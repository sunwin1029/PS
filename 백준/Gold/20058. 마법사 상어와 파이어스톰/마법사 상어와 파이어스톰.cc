#include <bits/stdc++.h>
using namespace std;

int n, q, boardSize;
vector <vector <int>> board;
int drow[4] = {-1, 1, 0, 0}; // 상하좌우
int dcol[4] = {0, 0, -1, 1};

void rotate(int q) {
    int partSize = 1 << q;
    vector <vector <int>> tmpBoard(partSize, vector<int>(partSize));

    // 시작좌표 루프
    for(int i = 0; i < boardSize; i += partSize) {
        for(int j = 0; j < boardSize; j += partSize) {
            // 판 회전시켜서 복사
            for(int r = 0; r < partSize; r++) {
                for(int c = 0; c < partSize; c++) {
                    tmpBoard[r][c] = board[i + partSize - 1 - c][j + r];
                }
            }

            // 옮기기
            for(int r = 0; r < partSize; r++) {
                for(int c = 0; c < partSize; c++) {
                    board[i + r][j + c] = tmpBoard[r][c];
                }
            }
        }
    }
}

void melt() {
    vector <vector <int>> tmpBoard(boardSize, vector <int>(boardSize));
    tmpBoard = board;

    for(int i = 0; i < boardSize; i++) {
        for(int j = 0; j < boardSize; j++) {
            int nearIceAmt = 0; 
            for(int x = 0; x < 4; x++) {
                int r = i + drow[x];
                int c = j + dcol[x];

                if(r < 0 || r >= boardSize || c < 0 || c >= boardSize) continue;

                if(board[r][c] > 0) {
                    nearIceAmt++;
                }
            }

            if(board[i][j] > 0 && nearIceAmt < 3) {
                tmpBoard[i][j]--;
            }
        }
    }

    board = tmpBoard;
}

int getAllIce() {
    int res = 0;
    for(int i = 0; i < boardSize; i++) {
        for(int j = 0; j < boardSize; j++) {
            res += board[i][j];
        }
    }

    return res;
}

int getBigIceAmt() {
    vector <vector <bool>> isCheck(boardSize, vector <bool> (boardSize, false));
    int maxSize = 0;

    for(int i = 0; i < boardSize; i++) {
        for(int j = 0; j < boardSize; j++) {
            if(isCheck[i][j] || board[i][j] <= 0) continue;

            queue <pair <int, int>> q;
            q.push({i, j});
            isCheck[i][j] = true;

            int iceSize = 1;

            while(!q.empty()) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(int x = 0; x < 4; x++) {
                    int newRow = r + drow[x];
                    int newCol = c + dcol[x];

                    if(newRow < 0 || newRow >= boardSize || newCol < 0 || newCol >= boardSize) {
                        continue;
                    }
                    if(isCheck[newRow][newCol] || board[newRow][newCol] <= 0) continue;

                    iceSize++;
                    isCheck[newRow][newCol] = true;
                    q.push({newRow, newCol});
                }

                maxSize = max(maxSize, iceSize);
            }  
        }
    }

    return maxSize;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    boardSize = 1 << n;

    board.resize(boardSize, vector<int>(boardSize));

    for(int i = 0; i < boardSize; i++) {
        for(int j = 0; j < boardSize; j++) {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < q; i++) {
        int tmp;
        cin >> tmp;

        rotate(tmp);
        melt();
    }

    cout << getAllIce() << "\n" << getBigIceAmt() << "\n";


    return 0;
}