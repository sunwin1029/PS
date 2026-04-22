#include <stdio.h>

int dp[1100][20];

int f(int a, int b) {
    if(b < 0)
    return 0;
    if(a < 1)
    return 1;
    if(dp[a][b] > 0)
    return dp[a][b] % 10007;
    dp[a][b] = f(a - 1, b) + f(a - 1, b - 1) + f(a - 1, b - 2) + f(a - 1, b - 3) + f(a - 1, b - 4) + f(a - 1, b - 5) + f(a - 1, b - 6) + f(a - 1, b - 7) + f(a - 1, b - 8) + f(a - 1, b - 9);
    return dp[a][b];
}

int main() {
    int n, res;
    scanf("%d", &n);
    res = 0;
    for(int i = 0; i <= 9; i++)
    res += f(n - 1, i);
    printf("%d", res % 10007);
    return 0;
}