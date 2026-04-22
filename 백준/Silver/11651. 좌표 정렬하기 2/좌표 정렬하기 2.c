#include <stdio.h>
#include <stdlib.h>
typedef struct str{
    int x;
    int y;
}str;
str arr[100010];
int compare(void *first, void *second) {
    str *a = (str *)first;
    str *b = (str *)second;
    
    if(a -> y == b -> y) {
        return a -> x - b -> x;
    }
    else
    return a -> y - b -> y;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }
    qsort(arr, n, sizeof(str), compare);
    for(int i = 0; i < n; i++) {
        printf("%d %d\n", arr[i].x, arr[i].y);
    }
    return 0;
}