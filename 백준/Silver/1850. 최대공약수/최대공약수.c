#include <stdio.h>

long long f(long long a, long long b) {
    return b ? f(b, a % b) : a;
}

int main() {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    long long n = f(a, b);
    for(int i = 0; i < n; i++)
    printf("1");

    return 0;
}