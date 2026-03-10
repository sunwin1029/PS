#include <bits/stdc++.h>
using namespace std;

long long dp[10100];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    dp[0] = 0;
    dp[1] = 1;

    cin >> n;

    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n] << "\n";

    return 0;
}