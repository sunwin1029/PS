#include <stdio.h>

int main() {
    int num_2 = 0;
    int num_5 = 0;
    int n, m, n_m;
    scanf("%d %d", &n, &m);
    n_m = n - m;
    for(long long check = 2; check <= n; check *= 2)
    num_2 += n / check;
    for(long long check = 5; check <= n; check *= 5)
    num_5 += n / check;
    //printf("check : %d %d\n", num_2, num_5);
    for(long long check = 2; check <= m; check *= 2)
    num_2 -= m / check;
    for(long long check = 5; check <= m; check *= 5)
    num_5 -= m / check;
    //printf("check : %d %d\n", num_2, num_5);
    for(long long check = 2; check <= n_m; check *= 2)
    num_2 -= n_m / check;
    for(long long check = 5; check <= n_m; check *= 5)
    num_5 -= n_m / check;
    //printf("check : %d %d\n", num_2, num_5);
    printf("%d", (num_2 < num_5 ? num_2 : num_5));
    
}