#include <stdio.h>

int main() {
    int m;
    scanf("%d", &m);
    int num = 1;
    int n = 1;
    if(m > 100)
    n = m - 100;
    int n_2 = 0;
    while(1) {
        num = n;
        n_2 += num;
        while(num >= 10) {
            n_2 += num % 10;
            num /= 10;
        }
        n_2 += num;
        if(n_2 == m)
        break;
        n++;
        n_2 = 0;
        if(n > m) {
            n = 0;
            break;
        }
    }
    printf("%d", n);
    return 0;
}