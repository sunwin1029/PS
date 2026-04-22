#include <stdio.h>

int main() {
    int t;
    int a, b, c, n;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
    a = 0;
    b = 0;
    c = 0;
    n = 0;
    
    
    scanf("%d %d %d", &a, &b, &c);
    
    if(a == 0) {
        if(b == 0 || c == 0)
        printf("R\n");
        continue;
    }
    if(b == 0 && c == 0) {
        printf("R\n");
        break;
    }
    b += a;
    c += a;
    n += a;
    
    if(b % 2 == 0 || c % 2 == 0)
    n += 1;
    
    if(n % 2 == 0)
    printf("B\n");
    else
    printf("R\n");
    }
    return 0;
}