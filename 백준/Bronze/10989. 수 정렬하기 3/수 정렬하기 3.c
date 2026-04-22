#include <stdio.h>
int ar[10001] = {0,};
int main() {
    int n;
    scanf("%d", &n);
    int x;
    for(int i  = 0; i < n; i++) {
        scanf("%d", &x);
        ar[x]++;
    }
    for(int i = 1; i <= 10000; i++) {
        while(ar[i] > 0) {
            printf("%d\n", i);
            ar[i]--;
        }
    }
    

    return 0;
}