#include <stdio.h>
#include <string.h>
int cp(int a, int b){
    return a<b?b:a;
}
char ar[1000001];
int asci[1000] = {0};
int main()
{
    scanf("%s", ar);
    int len;
    int code;
    len = strlen(ar);
    for(int i = 0; i < len; i++) {
        code = ar[i];
        // printf("%d", code);
        if(code > 91)
        asci[code - 32]++;
        else
        asci[code]++;
    }
    /*
    for(int i = 65; i < 91; i++) {
        printf("%c : %d\n",i,  asci[i]);
    }
    */
    int max = 0;
    int max_char;
    int check = 0;
    for(int i = 65; i < 91; i++) {
        if(asci[i] > max) {
            max = asci[i];
            max_char = i;
            check = 0;
            
        }
        else if(asci[i] == max) {
            
            check = 1;
        }
    }
  
    if(check == 1)
    printf("?");
    if(check == 0)
    printf("%c", max_char);
    
    return 0;
}