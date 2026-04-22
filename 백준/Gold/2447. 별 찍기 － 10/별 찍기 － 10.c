#include <stdio.h>

int star(int n, int x, int y) {
    if((x / n) % 3 == 1 && (y / n) % 3 == 1)
    printf(" ");
    else if(n / 3 == 0)
    printf("*");
    else
    star(n / 3, x, y);
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
        star(n, i, j);
        printf("\n");
    }
    

    return 0;
}