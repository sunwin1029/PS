#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>

bool compare(char* a, char* b) {
    int len;
    len = strlen(a) < strlen(b) ? strlen(a) : strlen(b);
    for(int i = 0; i < len; i++) {
        if(a[i] < b[i])
        return 1;
        if(a[i] > b[i])
        return 0;
    }
}

int main() {
    char arr[1001];
    // char suffix[1001][1001];
    int arr_len;
    
    std::cin >> arr;
    arr_len = strlen(arr);
    
    char** suffix = new char*[arr_len];
    for(int i = 0; i < arr_len; i++) {
        suffix[i] = new char[arr_len];
    }
    
    for(int i = 0; i < arr_len; i++) {
        strcpy(suffix[i], arr + i);
    }
    // printf("*** %s\n", suffix[0] + arr_len - 1);
    
    std::sort(suffix, suffix + arr_len, compare);
    
    for(int i = 0; i < arr_len; i++)
    printf("%s\n", suffix[i]);
    
    return 0;
}