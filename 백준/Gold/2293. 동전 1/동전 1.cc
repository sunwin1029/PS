#include <stdio.h>
#include <algorithm>

int ar[101]; // 동전 들어가는 배열
int dp[20000] = {0,};



int main() {
    dp[0] = 1;
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i  = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }
    std::sort(ar, ar + n);
    
    for(int i = 0; i < n; i++) {
            for(int j = ar[i]; j <= k; j++) {
                dp[j] += dp[j - ar[i]];
            }        
        }
        
    
    
    printf("%d", dp[k]);
    
    return 0;
}