#include <stdio.h>
int ar[1000001] = {0,};
int num = 1000001;
int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    for(int i  = 2; i <= n; i++)
    ar[i] = i;
     
    for(int i = 2; i <= n; i++) {
        if(ar[i] == 0)
        continue;
        
        for(int j = i * 2; j < num; j += i)
        ar[j] = 0;
        
        
    }
    
    for(int i = m; i <= n; i++) {
        if(ar[i] != 0)
        printf("%d\n", ar[i]);
    }
    
    
    return 0;
}