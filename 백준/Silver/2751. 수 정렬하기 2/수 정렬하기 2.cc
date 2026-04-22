#include <stdio.h>
#include <algorithm>
int ar[10000001];
bool comp(int a, int b) {
    return a < b;
}
int main() {
    int num;
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
    scanf("%d", &ar[i]);
    std::sort(ar, ar + num, comp);
    for(int i = 0; i < num; i++)
    printf("%d\n", ar[i]);
    

    return 0;
}