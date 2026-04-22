#include <stdio.h>
int cp(int a, int b) {
    return a > b ? a : b;
}
int w[102] = {0,}; // 물품 무게
int v[102] = {0,}; // 물품 가치
int dp[102][100001] = {0,};
int main() {
    int n, k;
    
    scanf("%d %d", &n, &k);
    
    for(int i = 1; i <= n; i++)
    scanf("%d %d", &w[i], &v[i]);
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            if(j >= w[i]) {
                   dp[i][j] = cp(v[i] + dp[i - 1][j - w[i]], dp[i - 1][j]);
            }
            else
            dp[i][j] = dp[i - 1][j];
        }
    }
    printf("%d", dp[n][k]);

    return 0;
}