#include <stdio.h>

int main() {
    int num;
    int get;
    int ans;
    int check[51] = {0};
    scanf("%d", &num);
    for(int i = 0; i < num; i++) {
        scanf("%d", &get);
        check[get]++;
    }
    for(int i = 50; i >= 0; i--)
    {
        if(check[i] == i) {
            ans = i;
            break;
        }
        ans = 0;
        if(check[0] != 0)
        ans = -1;
    }
    printf("%d", ans);
    return 0;
    
    
}
