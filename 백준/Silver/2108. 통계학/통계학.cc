#include <stdio.h>
#include <algorithm>
#include <math.h>
int ar[500001] = {0,};
int num[8010] = {0,};
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    scanf("%d", &ar[i]);
    std::sort(ar, ar + n);
    
    double sum = 0;
    for(int i = 0; i < n; i++)
    sum += ar[i];
    /*
    double sum_div;
    sum_div = sum / (double)n;
    */
    sum = sum / n;
    int sum_2 = round(sum);
    // printf("sum : %f\n", sum);
    // printf("****%f\n", sum_div);
    /*
    if(sum < 0 && sum - sum_div >= 0.5)
    sum = sum - 1;
    if(sum_div - sum >= 0.5 && sum > 0)
    sum = sum + 1;
    */
    int mid;
    mid = ar[n / 2];
    
    for(int i = 0; i < n; i++) {
        if(ar[i] < 0) {
            num[4000-ar[i]]++;
            continue;
        }
        num[ar[i]]++;
    }
    // printf("** %d ** ", num[4000]);
    int mode = 8001;
    int mode_2 = 8001;
    for(int i  = 4000; i >= 0; i--) {
        if(num[mode] == num[i]) {
            mode_2 = mode;
            mode = i;
        }
        if(num[mode] < num[i]) {
            mode = i;
            mode_2 = i;
        }
    }
    for(int i  = 4001; i <= 8000; i++) {
        if(num[mode] == num[i]) {
            mode_2 = mode;
            mode = i;
        }
        if(num[mode] < num[i]) {
            mode = i;
            mode_2 = i;
        }
    }
    if(mode_2 > 4000)
    mode_2 = -(mode_2 - 4000);
    
    int ran;
    ran = ar[n - 1] - ar[0];
    printf("%d\n", sum_2);
    printf("%d\n", mid);
    printf("%d\n", mode_2);
    printf("%d", ran);
    

    return 0;
}