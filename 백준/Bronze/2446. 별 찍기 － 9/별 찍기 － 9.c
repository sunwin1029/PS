#include <stdio.h>

int main() {
    int n;
    int star;
    int blank;
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        star = 2 * n - 1 - 2 * i;
        blank = i;
        for(int j = 0; j < blank; j++)
        printf(" ");
        for(int j = 0; j < star; j++)
        printf("*");
        
        printf("\n");
    }
    
    for(int i = n - 2; i >= 0; i--) {
        star = 2 * n - 1 - 2 * i;
        blank = i;
        for(int j = 0; j < blank; j++)
        printf(" ");
        for(int j = 0; j < star; j++)
        printf("*");
        
        printf("\n");
    }

    return 0;
}