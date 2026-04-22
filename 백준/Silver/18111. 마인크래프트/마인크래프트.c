#include <stdio.h>

int ar[502][502];
int t_ar[257];
int main() { 
    int n, m, b;
    int t = 0;
    int t_best = 2000000000;
    scanf("%d %d %d", &n, &m, &b);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
        scanf("%d", &ar[i][j]);
    }
    
    int block;
    int var;
    int height;
    for(int x = 0; x < 257; x++) {
        block = b;
        t = 0;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                       var = ar[i][j] - x;
                       block += var;
                       if(var > 0)
                       t += 2 * var;
                       else
                       t += (-var);
                       
                }
        }
        if(block < 0)
        continue;
        if(t_best >= t) {
            t_best = t;
            height = x;
        }
    }
    
    printf("%d %d", t_best, height);
    return 0;
}