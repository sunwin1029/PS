#include <stdio.h>

int main() {
    int num;
    int a = 1;
    long long total = 1;
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
    {
        a += 3;
        total += a;
    }
    printf("%lld", total % 45678);
    return 0;
}