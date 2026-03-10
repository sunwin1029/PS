#include <bits/stdc++.h>
#define MOD 1000000
using namespace std;

long long dp[2000100];
long long n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    int prev = 1;
    int current = 1;
    int repeat = 1;

    while(true) {
        if(prev % MOD == 0 && current % MOD == 1) break;
        repeat++;
        long long tmp = (prev + current) % MOD;
        prev = current;
        current = tmp;
    }

    n = n % repeat;
    dp[0] = 0;
    dp[1] = 1;

    // 0 1 2 3 4 5 6 7
    // 0 1 1 2 0 1 1 2

    for(int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    cout << dp[n] << "\n";

    return 0;
}