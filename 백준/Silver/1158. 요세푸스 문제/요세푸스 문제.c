#include <stdio.h>
int arr[5010];
int main() {
    int n, k;
    
    int location = 0;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) {
        arr[i] = i;
    }
    printf("<");
    for(int cnt = 0; cnt < n - 1; cnt++) {
        for(int i = 0; i < k; i++) {
            location++;
            if(location > n) {
                location = 1;
            }
            if(arr[location] == -1) {
                i--;
            }
        }
        printf("%d, ", arr[location]);
        arr[location] = -1;
    }
    for(int i = 0; i < k; i++) {
            location++;
            if(location > n) {
                location = 1;
            }
            if(arr[location] == -1) {
                i--;
            }
        }
        printf("%d>", arr[location]);

    return 0;
}