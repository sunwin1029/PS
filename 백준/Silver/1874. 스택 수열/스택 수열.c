#include <stdio.h>

int stack[200010];
int arr[200010];
int check_arr[200010];

int main() {
    int n;
    int best = 0;
    int stack_point = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        if(arr[i] > best)
        best = arr[i];
        if(arr[i] != best && arr[i] > arr[i - 1]) {
            printf("NO");
            return 0;
        }
        
        stack[i] = i;
    }
    for(int i = 1; i <= n; i++) {
        check_arr[arr[i]] = -1;
        if(arr[i] < arr[i - 1]) {
            for(int j = arr[i]; j < arr[i - 1]; j++) {
                if(check_arr[j] != -1) {
                    printf("NO");
                    return 0;
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        while(1) {
            if(arr[i] > stack_point) {
                stack_point++;
                if(stack[stack_point] != 0)
                printf("+\n");
                continue;
            }
            if(arr[i] == stack_point) {
                printf("-\n");
                stack[stack_point] = 0;
                stack_point--;
                break;
            }
            if(arr[i] < stack_point) {
                stack_point--;
            }
        }
        // printf("*%d\n", i);
    }

    return 0;
}