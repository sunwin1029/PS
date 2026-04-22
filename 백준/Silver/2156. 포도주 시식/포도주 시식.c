#include <stdio.h>

int ar[10002] = {0,};
int dp[2][10002] = {0,};
int dp_check[2][10002] = {0,};
int check = 0;

int cp(int a, int b) {
    return a>b?a:b;
}
int f(int check, int n) {
    if(n == 0)
    return 0;
    if(n == 1)
    return ar[1];
    if(dp_check[0][n] > 0 && check == 0)
    return dp[0][n];
    if(dp_check[1][n] > 0 && check == 1)
    return dp[1][n];

    if(check == 1) {
        if(n >= 3) {
            dp[1][n] = cp(f(0, n - 2), f(0, n - 3)) + ar[n];
            dp_check[1][n] = 1;
        }
        else {
            dp[1][n] = f(0, n - 2) + ar[n];
            dp_check[1][n] = 1;
        }
        return dp[1][n];
    }
    dp[0][n] = cp(f(1, n - 1), f(0, n - 2)) + ar[n];
    dp_check[0][n] = 1;
    return dp[0][n];
}
int main() {
    int num;
    scanf("%d", &num);
    for(int i = 1; i <= num; i++)
    scanf("%d", &ar[i]);

    printf("%d", cp(f(0, num), f(0, num - 1)));

    return 0;
}