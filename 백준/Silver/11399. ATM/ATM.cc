#include <stdio.h>
#include <algorithm>

int main() {
    int n;
    int ar[1001];
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    scanf("%d", &ar[i]);
    
    std::sort(ar, ar + n);
    
    int t = 0; // n번째 사람이 기다린 시간
    int tot = 0; // 총 소요되는 시간
    
    for(int i = 0; i < n; i++) {
        t += ar[i];
        tot += t;
    }
    
    printf("%d", tot);
    return 0;
}