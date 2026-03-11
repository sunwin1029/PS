#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> board;
int n, l;
int res = 0;

void programRow(int row) {
    bool possible = true;
    int prevHeight = board[row][0];
    vector<bool> usedAsile(n, false);

    for(int i = 1; i < n; i++) {
        if(abs(board[row][i] - prevHeight) > 1) {
            possible = false;
            break;
        } else if(board[row][i] > prevHeight) {
            for(int j = 1; j <= l; j++) {
                if(i - j < 0 || usedAsile[i - j] ||
                   board[row][i - j] != prevHeight) {
                    possible = false;
                    break;
                } else {
                    usedAsile[i - j] = true;
                }
            }
        } else if(board[row][i] < prevHeight) {
            for(int j = 0; j < l; j++) {
                if(i + j >= n || usedAsile[i + j] ||
                   board[row][i + j] != board[row][i]) {
                    possible = false;
                    break;
                } else {
                    usedAsile[i + j] = true;
                }
            }
            i += l - 1;
        }
        if(!possible) break;
        prevHeight = board[row][i];
    }

    if(possible) res++;
}

void programCol(int col) {
    bool possible = true;
    int prevHeight = board[0][col];
    vector<bool> usedAsile(n, false);

    for(int i = 1; i < n; i++) {
        if(abs(board[i][col] - prevHeight) > 1) {
            possible = false;
            break;
        } else if(board[i][col] > prevHeight) {
            for(int j = 1; j <= l; j++) {
                if(i - j < 0 || usedAsile[i - j] ||
                   board[i - j][col] != prevHeight) {
                    possible = false;
                    break;
                } else {
                    usedAsile[i - j] = true;
                }
            }
        } else if(board[i][col] < prevHeight) {
            for(int j = 0; j < l; j++) {
                if(i + j >= n || usedAsile[i + j] ||
                   board[i + j][col] != board[i][col]) {
                    possible = false;
                    break;
                } else {
                    usedAsile[i + j] = true;
                }
            }
            i += l - 1;
        }
        if(!possible) break;
        prevHeight = board[i][col];
    }

    if(possible) res++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> l;

    board.resize(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        programRow(i);
        programCol(i);
    }

    cout << res << "\n";

    return 0;
}