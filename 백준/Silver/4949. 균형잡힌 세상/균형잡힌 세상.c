 #include <stdio.h>
#include <string.h>

int main() {
    char arr[110];
    int stack[210];
    int len;
    
    int check;
    int stack_point = 1;
    memset(stack, 0, sizeof(stack));
    while(1) {
        memset(stack, 0, sizeof(stack));
        stack_point = 1;
        scanf("%[^\n]", arr);
        check = 0;
        if(strcmp(arr, ".") == 0)
        break;
        len = strlen(arr);
        // printf("%d\n", len);
        for(int i = 0; i < len; i++) {
            if(arr[i] == '(') {
                stack[stack_point] = 1;
                stack_point++;
            }
            if(arr[i] == ')') {
                stack_point--;
                if(stack[stack_point] != 1) {
                    check = 1;
                    break;
                }
                stack[stack_point] = 0;
            }
            if(arr[i] == '[') {
                stack[stack_point] = 2;
                stack_point++;
            }
            if(arr[i] == ']') {
                stack_point--;
                if(stack[stack_point] != 2) {
                    check = 1;
                    break;
                }
                stack[stack_point] = 0;
            }
        }
        if(stack_point != 1)
        check = 1;
        if(check == 1)
        printf("no\n");
        else
        printf("yes\n");
        getchar();
    }
    // printf("END");
    return 0;
}