#include <stdio.h>

int ar[1001];
int dp[1002] = {0,};
int cp(int a, int b) {
    return a > b ? a : b;
}
int main() {
    int n;
    int res = 1;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
    scanf("%d", &ar[i]);
    
    
    for(int k = n - 1; k >= 0; k--) {
        dp[k] = 1;
        for(int i = n - 1; i > k; i--) {
            if(ar[i] < ar[k]) {
                dp[k] = cp(dp[k], dp[i] + 1);
                // res = cp(dp[k], res);
            }
            res = cp(dp[k], res);
        }
    }
    
    printf("%d", res);

    return 0;
}