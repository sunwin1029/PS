#include <stdio.h>

int main() {
    long long A, B, C, D;
    int check = 10;
    int check_2 = 10;
    long long A_B, C_D; // A와 B가 모두 클 경우 int 범위 벗어날 수 있음
    scanf("%d %d %d %d", &A, &B, &C, &D);
    
    for(int i = B; i / 10 != 0; i /= 10)
    check *= 10;
    A_B = A * check + B;
    
    for(int i = D; i / 10 != 0; i /= 10)
    check_2 *= 10;
    C_D = C * check_2 + D;
    
    printf("%lld", A_B + C_D);
    

    return 0;
}