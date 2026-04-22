#include <stdio.h>

int main() {
    int x;
    int n;
    int a[101];
    int b[101];
    int tot = 0;
    
    scanf("%d", &x);
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &a[i], &b[i]);
        tot += a[i] * b[i];
    }
    if(x == tot) {
    printf("Yes");
    }
    else {
        printf("No");
    }
    return 0;
}