#include <bits/stdc++.h>
using namespace std;

int dp[100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= 20; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int n;
    cin >> n;

    cout << dp[n] << "\n";
    

    return 0;
}