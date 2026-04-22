#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int ar[101];
    int ans_num = 0;
    for(int i = 0; i < n; i++)
    scanf("%d", &ar[i]);
    for(int i = 0; i < n; i++) {
        if(ar[i] == 1)
        ans_num--;
        for(int j = 2; j < ar[i]; j++) {
            if(ar[i] % j == 0) {
                ans_num--;
                break;
            }
        }
        ans_num++;
        
    }
    printf("%d", ans_num);

    return 0;
}