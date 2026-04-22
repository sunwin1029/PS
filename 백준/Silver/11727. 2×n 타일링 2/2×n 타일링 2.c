#include <stdio.h>

int dp[1010];

int f(int n) {
    if(n == 0)
    return 0;
    if(n  == 1)
    return 1;
    if(n == 2)
    return 3;
    if(dp[n] > 0)
    return dp[n];
    dp[n] = f(n - 1) % 10007 + f(n - 2) * 2 % 10007 ;
    return dp[n];
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", f(n) % 10007);
    

    return 0;
}