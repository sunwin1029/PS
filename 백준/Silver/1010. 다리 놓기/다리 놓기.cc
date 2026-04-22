#include <stdio.h>

int dp[40][40];

long long factorial(int x) {
    if(x == 0)
    return 1;
    else
    return x * factorial(x - 1);
}
long long com(int a, int b) // combination
{
    int res = 1;
    for(int i = 1; i <= a; i++) {
        res *= b;
        res /= i;
        b--;
    }
    return res;
}

int main() {
    int t;
    int n, m;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        scanf("%d %d", &n, &m);
        
        printf("%lld\n", com(n, m));        
    }

    return 0;
}