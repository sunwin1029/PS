#include <stdio.h>
#include <string.h>

int main() {
    char arr[110];
    int check_arr[1000] = {0,};
    int arr_len;
    scanf("%s", arr);
    
    arr_len = strlen(arr);
    for(int i = 0; i < arr_len; i++) {
        check_arr[arr[i]]++;
    }
    
    for(int i = 97; i <= 122; i++)
    printf("%d ", check_arr[i]);
    
    return 0;
}