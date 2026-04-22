// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);
    int res = 0;
    int x = 1;
    int check = 0;
    while(1) {
        if(x * x < m) {
            x++;
            continue;
        }
        if(x * x >= m && x * x <= n) {
            break;
        }
        if(x * x > n) {
            printf("-1");
            return 0;
        }
    }
    
    for(int i = x; i * i <= n; i++) {
        res += i * i;
    }
    printf("%d\n", res);
    printf("%d", x * x);

    return 0;
}