#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    char ar[51];
    scanf("%s", ar);
    
    int num; // num = 등호가 나오기 전 숫자
    int len = strlen(ar); // 문자열의 길이 알기
    num = 0;
    int check = 0;
    int tot = 0; // 총합
    
    for(int i = 0; i < len; i++) {
        num = 0;
        while(ar[i] != '+' && ar[i] != '-' && i < len) {
            num += ((int)ar[i] - 48);
            if(ar[i] != '+' && ar[i] != '-' && i < len - 1) {
                num *= 10;
            }
            i++;
        }
        if(i < len - 1)
        num /= 10;
        // printf("\n%d", i);
        // printf("\n**%d", num);
        
        if(ar[i] == '+') {
            //i--;
            if(check == 0)
            tot += num;
            else
            tot -= num;
        } // 숫자 뒤에 +가 나옴
        if(ar[i] == '-') {
            //i--;
            if(check == 0) 
            tot += num;
            else
            tot -= num;
            check = 1;
        } // 숫자 뒤에 -가 나옴
        if(i == len) {
            if(check == 0) 
            tot += num;
            else
            tot -= num;
            break;
        } // 배열 마지막에 위치
        
        
    }
    printf("%d", tot);
    return 0;
}