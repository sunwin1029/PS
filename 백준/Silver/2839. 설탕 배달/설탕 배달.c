#include <stdio.h>
int main()
{
    int n;
    int thr = 0;
    int fiv = 0;
    int tot = 0;
    scanf("%d", &n);
    while(n % 5 != 0) {
       if(n < 2) {
            tot = -1;
            break;
        }
        n -= 3;
        thr++;
        
    }
    if(n % 5 == 0) {
        fiv = n / 5;
        tot = thr + fiv;
    }
    printf("%d", tot);
    return 0;
}