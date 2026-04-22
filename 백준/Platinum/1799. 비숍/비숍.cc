#include <bits/stdc++.h>
using namespace std;

int board[11][11];
bool isBishopBoard[11][11];
int n;
int res = 0;

int backtrack(int row, int col, int amt, int color);
bool canBishop(int row, int col);

// 북동부터 시계방향
int drow[4] = {-1, 1, 1, -1};
int dcol[4] = {1, 1, -1, -1};

int backtrack(int row, int col, int amt, int color) {
    int amtPutBishop = amt;
    if(col >= n) return backtrack(row + 1, 0, amt, color);
    if(row >= n) return amt;

    if((row + col) % 2 != color) return backtrack(row, col + 1, amt, color);

    if(board[row][col] == 0) return backtrack(row, col + 1, amt, color);

    if(canBishop(row, col)) {
        isBishopBoard[row][col] = true;
        amtPutBishop = backtrack(row, col + 1, amt + 1, color);
        isBishopBoard[row][col] = false;
    }
    return max(amtPutBishop, backtrack(row, col + 1, amt, color));
}

bool canBishop(int row, int col) {
    for(int i = 0; i < 4; i++) {
        int index = 1;
        int nr, nc;
        while(true) {
            nr = row + drow[i] * index;
            nc = col + dcol[i] * index;
            if(!(nr < n && nr >= 0 && nc < n && nc >= 0)) break;
            if(isBishopBoard[nr][nc]) return false;
            index++;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cin >> board[i][j];
    }

    cout << backtrack(0, 0, 0, 0) + backtrack(0, 0, 0, 1);

    return 0;
}