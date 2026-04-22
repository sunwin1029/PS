#include <bits/stdc++.h>
using namespace std;

vector <int> dp(100100, INT_MAX);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    dp[0] = 0;

    cin >> n;

    for(int i = 1; i * i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(j - i * i < 0) continue;
            dp[j] = min(dp[j - i * i] + 1, dp[j]);
        }
    }

    cout << dp[n] << "\n";

    return 0;
}