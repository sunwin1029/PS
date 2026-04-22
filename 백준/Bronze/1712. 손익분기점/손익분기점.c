#include <stdio.h>
int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int amt;
    if (b >= c)
    amt = -1;
    else if(a % (c - b) == 0)
    amt = a / (c - b) + 1;
    else
    amt = a / (c - b) + 1;
    printf("%d", amt);
    
    
    return 0;
}