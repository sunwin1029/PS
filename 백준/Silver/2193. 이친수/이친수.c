#include <stdio.h>

long long dp[100][2];

long long f(long long n, long long check) {
    if(n == 1) 
    return check;
    if(dp[n][check] > 0)
    return dp[n][check];
    if(check == 1)
    dp[n][check] = f(n - 1, 0);
    if(check == 0)
    dp[n][check] = f(n - 1, 0) + f(n - 1, 1);
    return dp[n][check];
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%lld", f(n, 0) + f(n, 1));

    return 0;
}