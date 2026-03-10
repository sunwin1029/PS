#include <bits/stdc++.h>
using namespace std;

int board[110][110];
long long dp[120][120];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    
    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
        cin >> board[i][j];
    }

    dp[0][0] = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(dp[i][j] == 0) continue;
            if(i == n - 1 && j == n - 1) continue;
            int tmp = board[i][j];
            dp[i + tmp][j] += dp[i][j];
            dp[i][j + tmp] += dp[i][j];
        }
    }


    /*
    cout << "\n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
        cout << dp[i][j] << " ";
        cout << "\n";
    }
    */
    cout << dp[n - 1][n - 1] << "\n";



    return 0;
}