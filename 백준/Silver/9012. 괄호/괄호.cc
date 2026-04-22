#include <stdio.h>
#include <string.h>

int main() {
    int n;
    int num_a = 0; // num_(
    int num_b = 0; // num_)
    char arr[51];
    int len;
    int check = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", arr);
        len = strlen(arr);
        num_a = 0;
        num_b = 0;
        check = 0;
        for(int j = 0; j < len; j++) {
            if(arr[j] == '(') {
                num_a++;
            }
            if(arr[j] == ')') {
                num_b++;
            }
            if(num_a < num_b)
            check = 1;
        }
        if(num_a != num_b)
        check = 1;
        if(check == 0)
        printf("YES\n");
        else
        printf("NO\n");
    }

    return 0;
}