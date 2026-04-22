#include <stdio.h>

int ar[11];
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        scanf("%d", &ar[i]);
    }
    
    int tot = 0; // 지금까지 합한 금액
    int res = 0; // res = 동전의 수
    for(int i = n - 1; i >= 0; i--) {
        while(tot + ar[i] <= k) {
            tot += ar[i];
            res++;
        }
    }
    
    printf("%d", res);
    
    return 0;
}