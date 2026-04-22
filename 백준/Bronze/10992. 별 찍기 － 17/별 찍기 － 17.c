#include <stdio.h>

int main() {
    int n;
    int star;
    int blank;
    
    scanf("%d", &n);
    
    for(int j = 0; j < n - 1; j++)
    printf(" ");
    printf("*\n");
    for(int i = 2; i <= n - 1; i++) {
        blank = n - i;
        for(int j = 0; j < blank; j++)
        printf(" ");
        printf("*");
        for(int j = 0; j < 2 * (i - 1) - 1; j++)
        printf(" ");
        printf("*");
        
        printf("\n");
    }
    if(n != 1) {
        for(int j = 0; j < n * 2 - 1; j++)
        printf("*");
    }

    return 0;
}