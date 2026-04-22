#include <bits/stdc++.h>
using namespace std;

bool board[20][20];
int n;

int queen(int row) {
    if(row == n) return 1;
    int res = 0;

    for(int i = 0; i < n; i++) {
        bool possible = true;

        // 위로
        for(int j = 0; j < row; j++) {
            if(board[j][i]) possible = false;
        }

        // 대각선
        for(int j = 1; j <= row; j++) {
            if(row - j >= 0 && i - j >= 0 && board[row - j][i - j]) possible = false;
            if(row - j >= 0 && i + j < n && board[row - j][i + j]) possible = false;
        }

        if(possible) {
            board[row][i] = true;
            res += queen(row + 1);
        }
        board[row][i] = false;
    }

    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cout << queen(0);

}