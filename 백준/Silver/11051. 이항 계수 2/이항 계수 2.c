#include <stdio.h>

int dp[1001][1001];

int f(int a, int b) {
    if(dp[a][b] != 0)
    return dp[a][b];
    if(b == 0) {
        dp[a][b] = 1;
        return dp[a][b];
    }
    if(b == 1) {
        dp[a][b] = a;
        return dp[a][b];
    }
    if(a == b) {
        dp[a][b] = 1;
        return dp[a][b];
    }
    dp[a][b] = f(a - 1, b) % 10007 + f(a - 1,b - 1) % 10007;
    return dp[a][b];
}

int main() {
    int n, k, res;
    res = 0;
    scanf("%d %d", &n, &k);
    res = f(n, k);
    printf("%d", res % 10007);
    
    
    return 0;
}