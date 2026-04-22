#include <stdio.h>

int main() {
    int n;
    int star;
    int blank;
    
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        star = i - 1;
        blank = n - i;
        for(int j = 0; j < blank; j++)
        printf(" ");
        for(int j = 0; j < star; j++)
        printf("* ");
        printf("*");
        
        printf("\n");
    }

    return 0;
}