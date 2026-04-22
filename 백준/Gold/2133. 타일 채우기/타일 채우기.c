#include <stdio.h>

int dp[100];
int f(int n) {
    if(n == 0)
    return 1;
    if(n % 2 != 0 || n < 0)
    return 0;
    if(n == 2)
    return 3;
    if(dp[n] > 0)
    return dp[n];
    dp[n] += 3 * f(n - 2);
    for(int i = 4; i <= n; i += 2) {
        dp[n] += 2 * f(n - i);
    }
    // dp[n] += 2; // n만의  새로 추가되는 개인 패턴
    return dp[n];
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", f(n));
    return 0;
}