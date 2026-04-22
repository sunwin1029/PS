#include <stdio.h>
#include <string.h>

long long dp[11][102] = {0,};

int f(int a, int n) {
    if(a == 0 && n == 1)
    return 0;
    if(dp[a][n] > 0)
    return dp[a][n] % 1000000000;
    if(a == 0)
    dp[a][n] = f(1, n - 1);
    else if(a == 9)
    dp[a][n] = f(8, n - 1);
    else
    dp[a][n] = f(a - 1, n - 1) + f(a + 1, n - 1);
    return dp[a][n] % 1000000000;
}

int main() {
    int len;
    long long res = 0;
    for(int i = 1; i <= 9; i++)
    dp[i][1] = 1;
    scanf("%d", &len);
    for(int i = 0; i <= 9; i++) {
        res += f(i, len) % 1000000000;
    }
    
    printf("%lld", res % 1000000000);

    return 0;
}