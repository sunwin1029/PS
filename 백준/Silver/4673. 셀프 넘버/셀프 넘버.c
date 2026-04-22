#include <stdio.h>
int main()
{
        int res = 0;
        int a[100000];
        for(int i = 1; i < 10000; i++)
        {
                a[i] = i;
        }
        for(int i = 1; i < 10000; i++)
        {
                res = i / 1000 + i % 1000 / 100 + i % 100 / 10 + i % 10 + i;
                a[res] = 0;
        }
        for(int i = 1; i < 10000; i++)
        {
                if(a[i] != 0)
                {
                        printf("%d\n", a[i]);
                }
        }
        return 0;
}
