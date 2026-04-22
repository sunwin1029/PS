#include <stdio.h>

int dp[100100];

int main() {
    int n;
    scanf("%d", &n);
    dp[0] = 100;
    for(int i = 1; i <= n; i++) {
        dp[i] = i;
    }
    for(int i = 1; i * i <= 100000; i++) {
        dp[i * i] = 1;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j * j <= i; j++) {
            if(dp[i] > dp[j * j] + dp[i - j * j])
            dp[i] = dp[j * j] + dp[i - j * j];
        }
    }
    printf("%d", dp[n]);
    return 0;
}