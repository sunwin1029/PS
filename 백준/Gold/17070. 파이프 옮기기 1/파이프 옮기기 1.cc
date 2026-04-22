#include <bits/stdc++.h>
using namespace std;

int n;
int home[20][20];
int dp[20][20][3];  // {row, col, way}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> home[i][j];
        }
    }

    dp[0][1][0] = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(home[i][j] == 1) continue;
            if(j - 1 >= 0) {
                dp[i][j][0] += dp[i][j - 1][0];
            }
            if(j - 1 >= 0 && i - 1 >= 0 && home[i - 1][j] != 1 && home[i][j - 1] != 1) {
                dp[i][j][2] += dp[i - 1][j - 1][0];
            }
            if(i - 1 >= 0) {
                dp[i][j][1] += dp[i - 1][j][1];
            }
            if(i - 1 >= 0 && j - 1 >= 0 && home[i - 1][j] != 1 && home[i][j - 1] != 1) {
                dp[i][j][2] += dp[i - 1][j - 1][1];
            }
            if(j - 1 >= 0) {
                dp[i][j][0] += dp[i][j - 1][2];
            }
            if(i - 1 >= 0) {
                dp[i][j][1] += dp[i - 1][j][2];
            }
            if(i - 1 >= 0 && j - 1 >= 0 && home[i - 1][j] != 1 && home[i][j - 1] != 1) {
                dp[i][j][2] += dp[i - 1][j - 1][2];
            }
        }
    }

    cout << dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2] << "\n";

    return 0;
}