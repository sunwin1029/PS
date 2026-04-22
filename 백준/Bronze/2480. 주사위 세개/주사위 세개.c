#include <stdio.h>
int main()
{
    int a, b, c, prize;
    scanf("%d %d %d", &a, &b, &c);
    if(a == b && b == c)
    {
        prize = 10000 + a * 1000;
    }
    else if(a == b || a == c)
    {
        prize = 1000 + a * 100;
    }
    else if(b == c)
    {
        prize = 1000 + b * 100;
    }
    else
    {
        if(a >= b && a >= c)
        {
            prize = a * 100;
        }
        if(b >= a && b >= c)
        {
            prize = b * 100;
        }
        if(c >= a && c >= b)
        {
            prize = c * 100;
        }
    }
    printf("%d", prize);
    return 0;
}