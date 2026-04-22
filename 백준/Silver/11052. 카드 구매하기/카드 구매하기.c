#include <stdio.h>

int arr[1010] = {0,};
int dp[1010];
int cp(int a, int b) {
    return a > b ? a : b;
}
int f(int n) {
    int max = 0;
    if(n == 0)
    return 0;
    if(dp[n] > 0)
    return dp[n];
    for(int i = 1; i < n; i++) {
        max = cp(max, f(i) + f(n - i));
    }
    max = cp(max, arr[n]);
    dp[n] = max;
    // printf("%d\n", dp[n]);
    return dp[n];
}
int main() {
    int n, res;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    for(int i = 1; i <= n; i++) {
        res = f(i);
        // printf("%d\n", i);
    }
    printf("%d", res);
    return 0;
}