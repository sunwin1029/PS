#include <stdio.h>

int main() {
    int a, b;
    int a_div[20] = {0,};
    int b_div[20] = {0,};
    int i;
    int num_a = 0;
    int num_b = 0;
    int max_div = 1;
    int min_mul = 1;
    scanf("%d %d", &a, &b);
    while(a > 1) {
        i = 2;
        while(1) {
            if(a % i == 0) {
                a /= i;
                a_div[num_a] = i;
                num_a++;
                break;
            }
            i++;
        }
    }
    while(b > 1) {
        i = 2;
        while(1) {
            if(b % i == 0) {
                b /= i;
                b_div[num_b] = i;
                num_b++;
                break;
            }
            i++;
        }
    }
    for(int i = 0; i < num_a; i++) {
        for(int j = 0; j < num_b; j++) {
            if(a_div[i] == b_div[j]) {
                max_div *= a_div[i];
                min_mul *= a_div[i];
                a_div[i] = 1;
                b_div[j] = 1;
                break;
            }
        }
    }

    for(int i = 0; i < num_a; i++) {
        // printf("a_div[%d] = %d", i, a_div[i]);
        
        min_mul *= a_div[i];
        // printf("    %d\n", min_mul);
    }
    for(int j = 0; j < num_b; j++) {
         // printf("b_div[%d] = %d", j, b_div[j]);
         
        min_mul *= b_div[j];
        // printf("    %d\n", min_mul);
    }
    /*
    for(int i = 0; i < num_a; i++)
    printf("%d\n", a_div[i]); 
    printf("///////////////\n");
    for(int i = 0; i < num_b; i++)
    printf("%d \n", b_div[i]);
    */
    printf("%d\n", max_div);
    printf("%d", min_mul);
    return 0;
    
}