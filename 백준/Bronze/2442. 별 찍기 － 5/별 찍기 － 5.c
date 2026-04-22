#include <stdio.h>

int main() {
    int n;
    int blank;
    int star;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        blank = n - i;
        star = 2 * i - 1;
        for(int j = 0; j < blank; j++)
        printf(" ");
        for(int j = 0; j < star; j++)
        printf("*");
        //for(int j = 0; j < blank; j++)
        // printf(" ");
        
        printf("\n"); // 한줄의 끝
        
    }
    

    return 0;
}