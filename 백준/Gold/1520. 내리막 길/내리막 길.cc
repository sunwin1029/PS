#include <bits/stdc++.h>
using namespace std;

vector <vector <int>> board;
vector <vector <int>> dp;
int m, n;

int drow[4] = {-1, 1, 0, 0}; // 상 하 좌 우
int dcol[4] = {0, 0, -1, 1};

int getCases(int row, int col) {
    int total = 0;
    for(int i = 0; i < 4; i++) {
        int beforeRow = row + drow[i];
        int beforeCol = col + dcol[i];

        if(beforeRow >= m || beforeRow < 0 || beforeCol >= n || beforeCol < 0) continue;

        if(board[row][col] >= board[beforeRow][beforeCol]) continue;

        if(dp[beforeRow][beforeCol] >= 0) total += dp[beforeRow][beforeCol];
        else {
            dp[beforeRow][beforeCol] = getCases(beforeRow, beforeCol);
            total += dp[beforeRow][beforeCol];
        }
    }

    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;

    board.resize(m, vector<int>(n));
    dp.resize(m, vector<int>(n, -1));
    dp[0][0] = 1;


    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    cout << getCases(m - 1, n - 1) << "\n";


    return 0;
}