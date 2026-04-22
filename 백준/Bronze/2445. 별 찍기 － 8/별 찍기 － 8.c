#include <stdio.h>

int main() {
    int n;
    int star;
    int blank;
    
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        star = i;
        blank = n - i;
        for(int j = 0; j < star; j++)
        printf("*");
        for(int j = 0; j < blank * 2; j++)
        printf(" ");
        for(int j = 0; j < star; j++)
        printf("*");
        printf("\n");
    }
    
    for(int i = n - 1; i >= 1; i--) {
        star = i;
        blank = n - i;
        for(int j = 0; j < star; j++)
        printf("*");
        for(int j = 0; j < blank * 2; j++)
        printf(" ");
        for(int j = 0; j < star; j++)
        printf("*");
        printf("\n");
    }

    return 0;
}