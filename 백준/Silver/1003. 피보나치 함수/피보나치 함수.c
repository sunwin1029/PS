#include <stdio.h>
#include <string.h>

long long dp_0[41] = {0,};
long long dp_1[41] = {0,};
long long f_0(int n) {
    if(dp_0[n] > 0)
    return dp_0[n];
    if(n == 0)
    return 1;
    if(n == 1)
    return 0;
    dp_0[n] = f_0(n - 1) + f_0(n - 2);
    return dp_0[n];
}

long long f_1(int n) {
    if(dp_1[n] > 0)
    return dp_1[n];
    if(n == 0)
    return 0;
    if(n == 1)
    return 1;
    dp_1[n] = f_1(n - 1) + f_1(n - 2);
    return dp_1[n];
}
int main() {
    int t;
    int n;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        
        scanf("%d", &n);
        memset(dp_0, 0, sizeof(long long) * 41);
        memset(dp_1, 0, sizeof(long long) * 41);
        printf("%lld %lld\n", f_0(n), f_1(n));
    }

    return 0;
}