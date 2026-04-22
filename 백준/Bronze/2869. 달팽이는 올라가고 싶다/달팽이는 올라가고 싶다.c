#include <stdio.h>
int main()
{
    int v;
    int a;
    int b;
    int day_1;
    int day_2;
    scanf("%d %d %d", &a, &b, &v);
    day_1 = (v - a) / (a - b);
    if(day_1 * (a - b) + a >= v)
    {
        day_2 = day_1 + 1;
    }
    else
    {
        day_2 = day_1 + 2;
    }
    printf("%d", day_2);
    return 0;
}