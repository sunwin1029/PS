#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct str{
    char string[51];
    int len;
    int check;
}str;

str arr[20010];
int compare(str *first, str *next) {
    str *a = first;
    str *b = next;
    int ch;
    if(a -> len == b -> len) {
        ch = strcmp(a -> string, b -> string);
        return ch;
    }
    return a -> len - b -> len;
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", arr[i].string);
        arr[i].len = strlen(arr[i].string);
        arr[i].check = 0;
    }
    
    qsort(arr, n, sizeof(str), compare);
    for(int i = 0; i < n; i++) {
        if(strcmp(arr[i].string, arr[i + 1].string) == 0)
        continue;
        printf("%s\n", arr[i].string);
    }

    return 0;
}