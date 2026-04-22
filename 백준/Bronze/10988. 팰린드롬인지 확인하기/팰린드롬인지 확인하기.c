#include <stdio.h>
#include <string.h>

int main() {
    char arr[101];
    scanf("%s", arr);
    int len;
    int check = 1;
    len = strlen(arr);
    for(int i = 0; i < len / 2; i++) {
        if(arr[i] != arr[len - i - 1]) {
            check = 0;
            break;
        }
    }
    printf("%d", check);

    return 0;
}