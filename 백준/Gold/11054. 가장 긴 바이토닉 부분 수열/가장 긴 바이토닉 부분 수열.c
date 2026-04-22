#include <stdio.h>

int ar[1001] = {0,};
int dp_a[1001] = {0,}; // dp_down_up
int dp_b[1001] = {0,}; // dp_up_down
int dp_res[1001] = {0,};
int cp(int a, int b) {
    return a > b ? a : b;
}
int main() {
    int n;
    int res = 0;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
    scanf("%d", &ar[i]);
    
 
    
    for(int i = 0; i < n; i++) {
        dp_a[i] = 1;
        for(int j = 0; j < i; j++) {
            if(ar[i] > ar[j]) {
                dp_a[i] = cp(dp_a[i], dp_a[j] + 1);
            }
        }
    }
    
    
    for(int i = n - 1; i >= 0; i--) {
        dp_b[i] = 1;
        for(int j = n - 1; j >= 0; j--) {
            if(ar[i] > ar[j]) {
                dp_b[i] = cp(dp_b[i], dp_b[j] + 1);
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        dp_res[i] = dp_a[i] + dp_b[i] - 1;
        res = cp(dp_res[i], res);
    }
    
    printf("%d", res);
    return 0;
}