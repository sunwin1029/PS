#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int num_2 = 0;
    int num_5 = 0;
    int num_10 = 0;
    int num_0 = 0;
    for(int i = 1; i <= n; i++) {
        int x = i;
        while(x % 2 == 0 || x % 5 == 0) {
            if(x % 10 == 0) {
                num_10++;
                x /= 10;
            }
            if(x % 5 == 0) {
                num_5++;
                x /= 5;
            }
            if(x % 2 == 0) {
                num_2++;
                x /= 2;
            }
        }
    }
    num_0 = num_10 + (num_2 <= num_5 ? num_2 : num_5);
    printf("%d", num_0);
    return 0;
}