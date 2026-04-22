#include <stdio.h>

long long dp[300][300];

long long f(int n, int k) {
    if(n == 0)
    return 1;
    if(n < 0 || k == 0)
    return 0;
    if(dp[n][k] > 0)
    return dp[n][k];
    for(int i = 0; i <= n; i++) {
        dp[n][k] += f(n - i, k - 1) % 1000000000;
    }
    return dp[n][k] % 1000000000;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%lld", f(n, k));
    
    return 0;
}