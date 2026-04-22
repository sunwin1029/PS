#include <stdio.h>
int main()
{
        int count = 0;
        int num;
        scanf("%d", &num);
        for(int i = 1; i <= num; i++)
        {
                if(i <= 99)
                {
                        count++;
                }
                if(100 <= i && i < 1000)
                {
                        if(i / 100 - i % 100 / 10 == i % 100 / 10 - i % 10)
                        {
                                count++;
                        }
                }
        }
        printf("%d", count);
        return 0;


}
