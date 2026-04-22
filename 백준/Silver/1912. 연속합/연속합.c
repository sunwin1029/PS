#include <stdio.h>
int cp(int a, int b){
    return a<b?b:a;
}
int ar[1000001];
int main() {
    int num;
    int tot = 0;
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
    scanf("%d", &ar[i]);
    int max = ar[0];
    for(int i = 0; i < num; i++)
    {
        tot += ar[i];
        max = cp(max, tot);
        if(tot < 0)
        tot = 0;
        
    }
    printf("%d", max);
    return 0;
}