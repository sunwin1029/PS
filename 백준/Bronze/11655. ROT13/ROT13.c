#include <stdio.h>
#include <string.h>

int main() {
    int arr_len;
    char arr[101];
    scanf("%[^\n]s", arr);
    arr_len = strlen(arr);
    for(int i = 0; i < arr_len; i++) {
        // arr[i]가 대문자인 경우
        if(arr[i] >= 65 && arr[i] <= 90) {
            // arr[i] 에서 13문자를 밀어도 Z를 넘지 않는 경우
            if(arr[i] <= 77)
            arr[i] += 13;
            // 13문자를 밀면 넘어가는 경우
            else
            arr[i] -= 13;
        }
        // arr[i]가 소문자인 경우
        if(arr[i] >= 97 && arr[i] <= 122) {
            if(arr[i] <= 109)
            arr[i] += 13;
            else
            arr[i] -= 13;
        }
    }
    printf("%s", arr);

    return 0;
}