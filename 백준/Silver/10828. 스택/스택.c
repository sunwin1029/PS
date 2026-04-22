// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
int arr[100001];
int f = 0;
void push() {
    f++;
    int x;
    scanf("%d", &x);
    arr[f] = x;
}
void pop() {
    if(f == 0) {
        printf("-1\n");
        return;
    }
    printf("%d\n", arr[f]);
    f--;
}
void size() {
    printf("%d\n", f);
}
void empty() {
    if(f == 0)
    printf("1\n");
    else
    printf("0\n");
}
void top() {
    if(f == 0)
    printf("-1\n");
    else
    printf("%d\n", arr[f]);
}


int main() {
    int n;
    int x;
    scanf("%d", &n);
    char ary[10];
    for(int i = 0; i < n; i++) {
        scanf("%s", &ary);
        if(strcmp(ary, "push") == 0)
        push();
        else if(strcmp(ary, "pop") == 0)
        pop();
        else if(strcmp(ary, "size") == 0)
        size();
        else if(strcmp(ary, "empty") == 0)
        empty();
        else if(strcmp(ary, "top") == 0)
        top();
        else
        printf("error\n");
    }
    
    

    return 0;
}