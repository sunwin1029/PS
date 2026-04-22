#include <stdio.h>

int ar[501] = {0,};
int ar_2[501] = {0,};
int dp[501] = {0,};
int dp_2[501] = {0,};

int cp(int a, int b) {
    return a > b ? a : b;
}
int main() {
    int n;
    scanf("%d", &n);
    int cha;
    int res = 0;
    int k = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", &cha);
        scanf("%d", &ar[cha - 1]);
    }
    
    for(int i = 0; i < 502; i++) {
        if(ar[i] != 0) {
            ar_2[k] = ar[i];
            k++;
        }
    }

    for(int i = 0; i < n; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if(ar_2[i] > ar_2[j] && ar_2[j] != 0) {
                dp[i] = cp(dp[i], dp[j] + 1);
            }
            res = cp(res, dp[i]);
        }
    }
    
    /*
    for(int i = k; i >= 0; i--) {
        dp[i] = 1;
        for(int j = i; j >= 0; j--) {
            if(ar_2[i] > ar_2[j]) {
                dp[i] = cp(dp[i], dp[j] + 1);
            }
            res = cp(res, dp[i]);
        }
    }
    */
    printf("%d", n - res);
    return 0;
}