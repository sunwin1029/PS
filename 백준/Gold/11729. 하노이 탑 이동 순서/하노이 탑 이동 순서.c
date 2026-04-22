#include <stdio.h>

int check = 1;
int hanoi_num(int num) {
    if(num == 1)
    return 1;
    return (hanoi_num(num - 1) * 2) + 1;
}

int hanoi(int num, int fr, int to, int by) {
    if(num == 1) {
        printf("%d %d\n",fr, to);
    }
    else {
        hanoi(num - 1, fr, by, to);
        printf("%d %d\n", fr, to);
        hanoi(num - 1, by, to, fr);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", hanoi_num(n));
    hanoi(n, 1, 3, 2);
    return 0;
}