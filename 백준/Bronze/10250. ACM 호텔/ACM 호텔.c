// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int t;
    int h;
    int w;
    int n;
    int h_res;
    int w_res;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        scanf("%d %d %d", &h, &w, &n);
        if(n / h == 0)
        w_res = 1;
        if(n % h == 0)
        w_res = n / h;
        else
        w_res = n / h + 1;
        
        if(n % h == 0)
        h_res = h;
        else if(n / h == 0)
        h_res = n;
        else
        h_res = n % h;
        if(w_res < 10)
        printf("%d0%d\n", h_res, w_res);
        else
        printf("%d%d\n", h_res, w_res);
        
        
    }

    return 0;
}