#include <stdio.h>

int que[200];

int find(int n, int m) {
    int best = 0;
    int amt = 0;
    int check = 0;
    while(1) {
        for(int i = check; i < n; i++) {
            if(que[i] > que[best])
            best = i;
        }
        for(int i = 0; i < check; i++) {
            if(que[i] > que[best])
            best = i;
        }
        check = best;
        que[check] = -1;
        amt++;
        if(best == m) {
            return amt;
        }
    }
}
int main() {
    int t;
    int n, m;
    scanf("%d", &t);
    for(int i = 0; i < t; i++) {
        scanf("%d %d", &n, &m);
        memset(que, 0, sizeof(que));
        for(int j = 0; j < n; j++) {
            scanf("%d", &que[j]);
        }
        printf("%d\n", find(n, m));
    }
    

    return 0;
}