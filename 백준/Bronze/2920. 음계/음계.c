#include <stdio.h>

int main() {
    int ar[9];
    for(int i = 0; i < 8; i++) {
        scanf("%d", &ar[i]);
    }
    int check = 2;
    if(ar[0] == 1) {
        check = 0;
        for(int i = 0; i < 8; i++) {
            if(ar[i] != i + 1)
            check = 2;
        }
    }
    if(ar[0] == 8) {
        check = 1;
        for(int i = 0; i < 8; i++) {
            if(ar[i] != 8 - i)
            check = 2;
        }
    }
    if(check == 0)
    printf("ascending");
    if(check == 1)
    printf("descending");
    if(check == 2)
    printf("mixed");
    return 0;
}