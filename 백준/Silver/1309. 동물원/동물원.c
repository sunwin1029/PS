#include <stdio.h>
int dp[100002] = {0,};
int f(int n) {
    dp[1] = 3;
    dp[2] = 7;
    if(n == 1)
    return dp[n];
    if(n == 2)
    return dp[n];
    
    if(dp[n] > 0)
    return dp[n];
    
    dp[n] = f(n - 1) * 2 % 9901 + f(n - 2) % 9901;
    return dp[n];
}
int main() {
    int n;
    scanf("%d", &n);
    int b;
    b = f(n);
    printf("%d", b % 9901);
    return 0;
}