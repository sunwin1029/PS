#include <stdio.h>

int main() {
    int ar[6];
    int tot = 0;
    for(int i = 0; i < 5; i++) 
    {
        scanf("%d", &ar[i]);
    }
    for(int i = 0; i < 5; i++)
    {
        tot += ar[i] * ar[i];
    }
    tot = tot % 10;
    printf("%d", tot);
    
    return 0;
}