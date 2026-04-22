#include <stdio.h>

int dp[2][100002] = {0,};
int st[2][100002] = {0,};
int cp(int a, int b) {
    return a > b ? a : b;
}
int cp_3(int a, int b, int c) {
    return cp(cp(a, b), c);
}
int f(int line, int num) {
    if(num < 0)
    return 0;
    if(dp[line][num] >= 0)
    return dp[line][num];
    if(line == 0) {
        dp[line][num] = cp_3(f(0, num - 2), f(1, num - 1), f(1, num - 2)) + st[line][num];
        return dp[line][num];
    }
    if(line == 1) {
        dp[line][num] = cp_3(f(1, num - 2), f(0, num - 1), f(0, num - 2)) + st[line][num];
        return dp[line][num];
    }
}
int main() {
    int t;
    int n;
    int res;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        scanf("%d", &n);
        memset(dp, -1, sizeof(dp));
        memset(st, 0, sizeof(st));
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < n; j++)
            scanf("%d", &st[i][j]);
        }
        /*
        dp[0][0] = st[0][0];
        dp[1][0] = st[1][0];
        dp[0][1] = st[0][1] + st[1][0];
        dp[1][1] = st[0][0] + st[1][1];
        */
        res = cp(f(0, n), f(1, n));
        printf("%d\n", res);
    }
    
    return 0;
}