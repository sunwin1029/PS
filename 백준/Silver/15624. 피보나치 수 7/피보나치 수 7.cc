#include <bits/stdc++.h>
#define MOD 1'000'000'007
using namespace std;

long long dp[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    cout << dp[n] << "\n";

    return 0;
}