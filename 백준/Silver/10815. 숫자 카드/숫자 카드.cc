#include <stdio.h>
#include <algorithm>
#define num 500001

int arr[num];
int ch_arr[num];

void b_search(int arr[], int size, int n) {
    int min = 0;
    int max = size - 1;
    int mid;
    while(1) {
        if(min > max) {
            printf("0 ");
            break;
        }
        mid = (min + max) / 2;
        if(n == arr[mid]) {
            printf("1 ");
            break;
        }
        if(n > arr[mid])
        min = mid + 1;
        else
        max = mid - 1; 
    }
}
int main() {
    int n, m;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    scanf("%d", &arr[i]);
    
    std::sort(arr, arr + n);
    
    scanf("%d", &m);
    
    for(int i = 0; i < m; i++)
    scanf("%d", &ch_arr[i]);

    
    for(int i = 0; i < m; i++)
    b_search(arr, n, ch_arr[i]);
    
    return 0;
}