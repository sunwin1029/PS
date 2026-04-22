#include <iostream>
#include <stdio.h>
#include <string.h>

struct edit{
    char c;
    struct edit* before;
    struct edit* next;
}edit;

struct edit* cursor = NULL;
struct edit* head = NULL;
//struct edit* tail = NULL;

void P_2(char x) {
    struct edit* node = new struct edit;
    node -> c = x;
    node -> before = NULL;
    node -> next = NULL;
    if(head -> next == NULL) {
        head -> next = node;
        node -> before = head;
        cursor = node;
    }
    else {
        cursor -> next = node;
        node -> before = cursor;
        cursor = node;
    }
}

void P() {
    char x;
    scanf(" %c", &x);
    struct edit* node = new struct edit;
    node -> c = x;
    node -> before = NULL;
    node -> next = NULL;
    if(head -> next == NULL) {
        head -> next = node;
        node -> before = head;
        cursor = node;
    }
    else {
        if(cursor -> next == NULL) {
            cursor -> next = node;
            node -> before = cursor;
            cursor = node;
        }
        else {
            cursor -> next -> before = node;
            node -> next = cursor -> next;
            cursor -> next = node;
            node -> before = cursor;
            cursor = node;
        }
    }
}

void L() {
    if(cursor -> before != NULL)
    cursor = cursor -> before;
}

void D() {
    if(cursor -> next != NULL)
    cursor = cursor -> next;
}

void B() {
    if(cursor -> before != NULL) {
        if(cursor -> next != NULL) {
            cursor -> next -> before = cursor -> before;
            cursor -> before -> next = cursor -> next;
            cursor = cursor -> before;
        }
        else {
            cursor -> before -> next = NULL;
            cursor = cursor -> before;
        }
    }
}
int main() {
    struct edit* new_node = new struct edit;
    head = new_node;
    head -> before = NULL;
    head -> next = NULL;
    head -> c = NULL;
    int n;
    char order = 'x';
    char arr[600001];
    scanf("%s", arr);
    
    int len = strlen(arr);
    for(int i = 0; i < len; i++) P_2(arr[i]);
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        scanf(" %c", &order);
        if(order == 'P') 
        P();
        else if(order == 'L') 
        L();
        else if(order == 'D') 
        D();
        else if(order == 'B') 
        B();
        else
        printf("error\n");
    }
    cursor = head;
    if(cursor -> next == NULL)
    return 0;
    cursor = cursor -> next;
    while(1) {
        printf("%c", cursor -> c);
        if(cursor -> next == NULL)
        break;
        cursor = cursor -> next;

    }

    return 0;
}