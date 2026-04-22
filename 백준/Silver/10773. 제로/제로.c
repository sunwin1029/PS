#include <stdio.h>

int arr[100001];
int main() {
    int x, k, check;
    int sum = 0;
    scanf("%d", &k);
    
    for(int i = 0; i < k; i++) {
        check = i;
        scanf("%d", &x);
        if(x == 0) {
            //printf("check!");
            check--;
            while(arr[check] == 0) {
                check--;
            }
            arr[check] = 0;
            //printf("arr[%d] = %d\n",check,  arr[check]);
        }
        else
        arr[check] = x;
    }
    for(int i = 0; i < k; i++) {
        //printf("i : %d\n", arr[i]);
        sum += arr[i];
    }
    printf("%d", sum);
    return 0;
}