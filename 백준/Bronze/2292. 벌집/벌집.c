#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int move = 1;
    int x = 1;
    int plus = 6;
    while(1) {
        if(x >= n)
        break;
        x += plus;
        plus += 6;
        move++;
    }
    printf("%d", move);
    return 0;
}