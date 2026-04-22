#include <stdio.h>

int ar[501][501] = {0,};
int dp[501][501] = {0,};

int cp(int a, int b) {
    return a > b ? a : b;
}
int f(int s, int n) {
    if(dp[s][n] > 0)
    return dp[s][n];
    if(s == 0)
    return ar[0][0];
    if(n == 0) {
        dp[s][n] = f(s - 1, n) + ar[s][n];
        return dp[s][n];
    }
    
    if(n == s) {
        dp[s][n] = f(s - 1, n - 1) + ar[s][n];
        return dp[s][n];
    }
    
    dp[s][n] = cp(f(s - 1, n - 1), f(s - 1, n)) + ar[s][n];
    return dp[s][n];
    
}

int main() {
    int num, res;
    scanf("%d", &num);
    for(int i = 0; i < num; i++) {
        for(int j = 0; j <= i; j++)
        scanf("%d", &ar[i][j]);
    }
    res = 0;
    for(int i = 0; i < num; i++)
    res = cp(res, f(num, i));
    printf("%d", res);

    return 0;
}