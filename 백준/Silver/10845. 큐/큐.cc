#include <stdio.h>
#include <string.h>

int arr[100000];
int* ptr = arr;
int x = 0;
void push() {
    x++;
    // ptr = arr + x;
    scanf("%d", ptr + x);
}
void pop() {
    if(x == 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", *(ptr + 1));
    *(ptr + 1) = 0;
    ptr++;
    x--;
}
void size() {
    printf("%d\n", x);
}
void empty() {
    if(x == 0)
    printf("1\n");
    else
    printf("0\n");
}
void front() {
    if(x == 0)
    printf("-1\n");
    else
    printf("%d\n", *(ptr + 1));
}
void back() {
    if(x == 0)
    printf("-1\n");
    else
    printf("%d\n", *(ptr + x));
}
int main() {
    int n;
    scanf("%d", &n);
    char str[20];
    for(int i = 0; i < n; i++) {
        scanf("%s", str);
        if(strcmp(str, "push") == 0) {
            push();
            continue;
        }
        if(strcmp(str, "pop") == 0) {
            pop();
            continue;
        }
        if(strcmp(str, "size") == 0) {
            size();
            continue;
        }
        if(strcmp(str, "empty") == 0) {
            empty();
            continue;
        }
        if(strcmp(str, "front") == 0) {
            front();
            continue;
        }
        if(strcmp(str, "back") == 0) {
            back();
            continue;
        }
    }

    return 0;
}