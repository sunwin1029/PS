#include <stdio.h>

int f(int k, int n) {
    if(k == 0)
    return n;
    int res = 0;
    for(int i = 1; i < n + 1; i++) {
        res += f(k - 1, i);
    }
    return res;
}
int main() {
    int t, k, n, res;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        scanf("%d", &k);
        scanf("%d", &n);
        
        res = f(k, n);
        printf("%d\n", res);
    }
    
    return 0;
}