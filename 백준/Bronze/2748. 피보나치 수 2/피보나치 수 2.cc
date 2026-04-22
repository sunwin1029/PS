#include <bits/stdc++.h>
using namespace std;
long long dp[100] = {0,};
long long f(int n) {
    if(n == 0 || n == 1) return n;
    if(dp[n] > 0) return dp[n];
    dp[n] = f(n - 1) + f(n - 2);
    return dp[n];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    cout << f(n);

    return 0;
}