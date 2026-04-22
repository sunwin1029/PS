#include <stdio.h>
int cp(int a, int b) {
    return a>b?a:b;
}
int main() {
    int n, m;
    int ar[101];
    int best = 0;
    int num = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) 
    scanf("%d", &ar[i]);
    for(int i = 0; i < n; i++) {
        num += ar[i];
        for(int j = i + 1; j < n; j++) {
            num += ar[j];
            for(int k = j + 1; k < n; k++) {
                num += ar[k];
                if(num > m) {
                    num -= ar[k];
                    continue;
                }
                best = cp(num, best);
                num -= ar[k];
            }
            num -= ar[j];
        }
        num -= ar[i];
    }
    
    printf("%d", best);
    return 0;
}