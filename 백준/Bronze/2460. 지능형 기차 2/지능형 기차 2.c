#include <stdio.h>
int main()
{
    int total = 0;
    int total_after;
    int best_total = 0;
    int in;
    int out;
    for(int i = 0; i < 10; i++)
    {
        scanf("%d %d", &out, &in);
        total_after = total + in - out;
        if(total_after > best_total)
        {
            best_total = total_after;
        }
        total = total_after;
        
    }
    printf("%d", best_total);
    return 0;
}