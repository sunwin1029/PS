#include <stdio.h>
#include <string.h>

int main() {
    char arr[110];
    char x = 0;
    int check;
    int arr_len;
    while(scanf("%[^\n]s", arr) != EOF)
    {
        int small_char = 0;
        int large_char = 0;
        int num = 0;
        int blank = 0;
        char check;
        arr_len = strlen(arr);
        for(int i = 0; i < arr_len; i++) {
            if((char)arr[i] >= 97 && (char)arr[i] <= 122)
            small_char++;
            else if((char)arr[i] >= 65 && (char)arr[i] <= 90)
            large_char++;
            else if((char)arr[i] >= 48 && (char)arr[i] <= 57)
            num++;
            else if((char)arr[i] == 32)
            blank++;
        }
        printf("%d %d %d %d\n", small_char, large_char, num, blank);
        check = getchar();
        if(check == EOF) break;
    }
    
    return 0;
}