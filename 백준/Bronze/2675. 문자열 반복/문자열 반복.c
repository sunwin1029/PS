#include <stdio.h>
#include <stdio.h>
int main() {
    int num;
    int re;
    int len;
    char ar[21];
    scanf("%d", &num);
    for(int i = 0; i < num; i++) {
        scanf("%d", &re);
        scanf("%s", ar);
        len = strlen(ar);
        for(int i = 0; i < len; i++) {
            for(int j = 0; j < re; j++) {
                printf("%c", ar[i]);
            }
        }
        printf("\n");
    }
    
    return 0;
}