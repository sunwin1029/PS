#include <iostream>
#include <stdio.h>
using namespace std;
int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%.20f", (double)a / (double)b);
    return 0;
}