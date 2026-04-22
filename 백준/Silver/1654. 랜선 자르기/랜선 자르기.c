#include <stdio.h>

int cp(int a, int b) {
    return a > b ? a : b;
}
int main() {
    int k, n;
    long long ar[10001];
    long long max = 0;
    scanf("%d %d", &k, &n);
    for(int i = 0; i < k; i++) {
        scanf("%lld", &ar[i]);
    }
    for(int i = 0; i < k; i++) {
        max = cp(max, ar[i]);
    }
    
    long long range_max = max;
    long long range_min = 1;
    long long range_mid;
    int amt;
    while(1) {
        amt = 0;
        range_mid = (range_max + range_min) / 2;
        if(range_max == range_mid || range_min == range_mid)
        break;
        for(int i = 0; i < k; i++) {
            amt += ar[i] / range_mid;
        }
        if(amt < n)
        range_max = range_mid;
        else
        range_min = range_mid;
    }
    for(int i = 0; i < k; i++) {
            amt += ar[i] / range_max;
        }
    if(amt < n)
    printf("%lld", range_min);
    else
    printf("%lld", range_max);
    
    
    

    return 0;
}