#include <stdio.h>
#include <string.h>

int main() {
    int n;
    int len;
    int num = 0; // 그룹 단어의 갯수
    int check_ar[1000] = {0,}; // 한번 나온 알파벳을 체크하는 배열
    char str[101];
    int x = 0; // 그룹 단어 조건(0일 경우 그룹단어, 아니면 x)
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", str);
        len = strlen(str);
        if(len == 1) {
            num++;
            continue;
        }
        check_ar[(int)str[0]]++;
        for(int j = 1; j < len; j++) {
            if(str[j] != str[j - 1])
            check_ar[(int)str[j]]++;
            if(check_ar[(int)str[j]] > 1)
            x = 1;
            // printf("%d : %s\n", i, str);
            }

        if(x == 0)
        num++;
        
        memset(check_ar, 0, sizeof(int) * 1000); // 초기화
        x = 0; // 초기화
    }
    printf("%d", num);
    return 0;
}