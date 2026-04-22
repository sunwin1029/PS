#include <stdio.h>

int main() {
    int arr[31] = {0,};
    int check;
    
    for(int i = 1; i <= 28; i++) {
        scanf("%d", &check);
        arr[check] = 1;
    }
    
    for(int i = 1; i <= 30; i++) {
        if(arr[i] == 0) {
            printf("%d\n", i);
        }
    }
    
    return 0;
}