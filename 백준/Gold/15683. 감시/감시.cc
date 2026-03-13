#include <bits/stdc++.h>
#define UP 0
#define DOWN 2
#define LEFT 3
#define RIGHT 1
using namespace std;

int n, m;
int cctvAmt = 0;
vector <vector <int>> board;

void changeBoard(vector <vector <int>> &tmpState, int row, int col, int dir) {
    if(dir == LEFT) {
        col--;
        while(col >= 0 && tmpState[row][col] != 6) {
            if(tmpState[row][col] == 0) {
                tmpState[row][col] = -1;
            }
            col--;
        }
    }
    if(dir == RIGHT) {
        col++;
        while(col < m && tmpState[row][col] != 6) {
            if(tmpState[row][col] == 0) {
                tmpState[row][col] = -1;
            }
            col++;
        }
    }
    if(dir == DOWN) {
        row++;
        while(row < n && tmpState[row][col] != 6) {
            if(tmpState[row][col] == 0) {
                tmpState[row][col] = -1;
            }
            row++;
        }
    }
    if(dir == UP) {
        row--;
        while(row >= 0 && tmpState[row][col] != 6) {
            if(tmpState[row][col] == 0) {
                tmpState[row][col] = -1;
            }
            row--;
        }
    }
}

int getBlind(vector <vector <int>> &tmpState) {
    int amt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(tmpState[i][j] == 0) amt++;
        }
    }
    return amt;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int res = INT_MAX;
    board.resize(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] > 0 && board[i][j] < 6) {
                cctvAmt++;
            }
        }
    }

    for(int i = 0; i < (1 << (2 * cctvAmt)); i++) {
        vector <vector <int>> tmpState = board; // 판 복사

        int cctvNum = 0; // 현재 cctv index
        int dir; // 방향
        int type; // cctv 종류
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                type = tmpState[row][col];
                // cctv 라면
                if(type > 0 && type < 6) {
                    dir = (i >> (2 * cctvNum)) & 3;
                    cctvNum++;

                    switch(type) {
                        case 1:
                            changeBoard(tmpState, row, col, dir);
                            break;
                        case 2:
                            changeBoard(tmpState, row, col, dir);
                            changeBoard(tmpState, row, col, (dir + 2) % 4);
                            break;
                        case 3:
                            changeBoard(tmpState, row, col, dir);
                            changeBoard(tmpState, row, col, (dir + 1) % 4);
                            break;
                        case 4:
                            changeBoard(tmpState, row, col, dir);
                            changeBoard(tmpState, row, col, (dir + 1) % 4);
                            changeBoard(tmpState, row, col, (dir + 3) % 4);
                            break;
                        case 5:
                            for(int x = 0; x < 4; x++) {
                                changeBoard(tmpState, row, col, x);
                            }
                            break;
                    }  
                }
            }
        }

        res = min(res, getBlind(tmpState));
    }


    cout << res << "\n";

    return 0;
}