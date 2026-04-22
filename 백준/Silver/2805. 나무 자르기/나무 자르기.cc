#include <stdio.h>
#include <algorithm>

long long ar[1000001];
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i= 0; i < n; i++)
    scanf("%lld", &ar[i]);
    std::sort(ar, ar + n);
    int cut_tree = 1;
    long long tot = 0;
    long long dis;
    int j = n;
    while(1) {
        dis = ar[j - 1] - ar[j - 2];
        tot += cut_tree * dis;
        if(tot >= m) {
            tot -= cut_tree * dis;
            dis = (m - tot) / cut_tree;
            if((m - tot) % cut_tree != 0)
            dis++;
            break;
        }
        cut_tree++;
        j--;
    }
    printf("%lld", ar[j - 1] - dis);
        

    return 0;
}