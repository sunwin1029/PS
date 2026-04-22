#include <stdio.h>
long long dp[101] = {0,};
long long f(int n) {
    if(dp[n] > 0)
    return dp[n];
    if(n < 4) {
        dp[n] = 1;
        return dp[n];
    }
    if(n == 4 || n == 5) {
        dp[n] = 2;
        return dp[n];
    }
    if(n > 4) {
        dp[n] = f(n - 1) + f(n - 5);
        return dp[n];
    }
}

int main() {
    int t;
    scanf("%d", &t);
    int x;
    for(int i = 0; i < t; i++) {
        scanf("%d", &x);
        printf("%lld\n", f(x));
    }

    return 0;
}