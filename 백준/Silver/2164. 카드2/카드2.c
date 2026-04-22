#include <stdio.h>

int front = -1;
int back = -1;
int arr[1000002] = {0,};

void plus_num(int num){
    back += 1;
    arr[back] = num;
    return;
}


int del_num() {
    int tmp;
    front += 1;
    tmp = arr[front];
    arr[front] = 0;
    return tmp;
}

int main() {
    int n, tmp;
    tmp = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        plus_num(i);
    }
    // printf("%d\n", back);
    
    while(1) {
        tmp = del_num();
        if(front == back)
        break;
        tmp = del_num();
        if(front == back)
        break;
        plus_num(tmp);
    }
    
    printf("%d", tmp);

    return 0;
}