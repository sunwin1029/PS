#include <stdio.h>

int cp(int a, int b) {
    return a > b ? a : b;
}
int main() {
    int a = 1;
    int b = 1;
    int c = 1;
    int best;
    int check;
    while(1) {
        scanf("%d %d %d", &a, &b, &c);
        if(a == 0)
        break;
        best = cp(cp(a, b), c);
        if(a == best) {
            if(a * a == b * b + c * c)
            printf("right\n");
            else
            printf("wrong\n");
        }
        if(b == best) {
            if(b * b == a * a + c * c)
            printf("right\n");
            else
            printf("wrong\n");
        }
        if(c == best) {
            if(c * c == a * a + b * b)
            printf("right\n");
            else
            printf("wrong\n");
        }
    }

    return 0;
}