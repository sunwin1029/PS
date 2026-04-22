#include <stdio.h>

int main()
{
    int hou;
    int min;
    int time;
    scanf("%d %d", &hou, &min);
    scanf("%d", &time);
    int hou_min;
    int new_hou;
    int new_min;
    hou_min = hou * 60 + min + time;
    if(hou_min >=  1440)
    {
        hou_min = hou_min - 1440;
    }
    new_hou = hou_min / 60;
    new_min = hou_min % 60;
    printf("%d %d", new_hou, new_min);
    return 0;
    
    
}