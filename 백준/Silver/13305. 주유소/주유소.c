#include <stdio.h>

long long dis[100010];
long long cost[100010];

int main() {
    int n;
    long long tot = 0; // 총 기름값
    int min; // 온 도시 중 기름 최솟값
    scanf("%d", &n);
    for(int i = 1; i <= n - 1; i++) {
        scanf("%lld", &dis[i]);
    }
    
    for(int i = 1; i <= n; i++)
    scanf("%lld", &cost[i]);
    
    min = cost[1];
    for(int i = 1; i <= n - 1; i++) {
        min = min < cost[i] ? min : cost[i];
        tot += min * dis[i];
    }
    printf("%lld", tot);
    
    return 0;
}