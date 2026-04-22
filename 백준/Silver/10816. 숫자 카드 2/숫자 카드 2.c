#include <stdio.h>
int card[20000002];
int ar[500001];
int main() {
    int n, x;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        if(x >= 0)
        card[x]++;
        else if(x < 0) {
            card[-x + 10000000]++;
            // printf("%d", -x + 10000000);
        }
    }
    // printf("\n//////////////////////\n");
    int m;
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &ar[i]);
    }
    for(int i = 0; i < m; i++) {
        if(ar[i] >= 0)
        printf("%d ", card[ar[i]]);
        else {
            printf("%d ", card[-ar[i] + 10000000]);
        }
    
    }

    return 0;
}