#include <stdio.h>

int factorize(int n) {
    if(n == 1)
    return;
    for(int i = 2; i <= n; i++) {
        if(n % i == 0) {
            printf("%d\n", i);
            n /= i;
            i--;
        }
    }
    return 0;
    
}

int main() {
    int n;
    scanf("%d", &n);
    factorize(n);
    

    return 0;
}