#include <stdio.h>

int n_1 = 0;
int n_2 = 0;
int ar[50] = {0,};
int f_1(int n) {
    
    if(n == 1 || n == 2) {
        n_1++;
        return 1;
    }
    return f_1(n - 1) + f_1(n - 2);
}
int f_2(int n) {
    ar[1] = 1;
    ar[2] = 1;
    for(int i = 3; i <= n; i++) {
        n_2++;
        ar[i] = ar[i - 1] + ar[i - 2];
    }
    return ar[n];
}
int main() {
    int k;
    scanf("%d", &k);
    f_1(k);
    f_2(k);
    printf("%d %d", n_1, n_2);

    return 0;
}