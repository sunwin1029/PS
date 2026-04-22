#include <stdio.h>

int cp(int a, int b) {
    return a < b ? a : b;
}
int main() {
    int x, y, w, h;
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &w);
    scanf("%d", &h);
    int res;
    res = cp(cp(w - x, x), cp(h - y, y));
    printf("%d", res);
    return 0;
}