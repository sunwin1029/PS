#include <stdio.h>
#include <string.h>
int main() {
    char n_1[10010] = "";
    char n_2[10010] = "";
    char n_1_new[10010] = "";
    char n_2_new[10010] = "";
    char n_res[10010] = "";
    char n_res_new[10010] = "";
    scanf("%s", n_1);
    scanf("%s", n_2);
    int len1 = strlen(n_1);
    int len2 = strlen(n_2);
    for(int i = 0; i < len1; i++) {
        n_1_new[i] = n_1[len1 - 1 - i];
    }
    
    for(int i = 0; i < len2; i++) {
        n_2_new[i] = n_2[len2 - 1 - i];
    }
    // printf("%s %s\n", n_1_new, n_2_new);
    int len_longer = len1 > len2 ? len1 : len2;
    // printf("%d\n", len_longer);
    int check = 0; // check checks more than 10
    int sum;
    for(int i = 0; i < len_longer; i++) {
        if(n_1_new[i] == NULL) 
        n_1_new[i] = '0';
        if(n_2_new[i] == NULL) 
        n_2_new[i] = '0';
        sum = (n_1_new[i] - 48) + (n_2_new[i] - 48) + check;
        if(sum >= 10) {
            check = 1;
            sum -= 10;
        }
        else
        check = 0;
        
        n_res[i] = sum + 48;
    }
    if(check == 1) {
        len_longer++;
        n_res[len_longer - 1] = 49;
    }
    for(int i = 0; i < len_longer; i++) {
        n_res_new[i] = n_res[len_longer - 1 - i];
    }
    
    printf("%s", n_res_new);
    
    return 0;
}