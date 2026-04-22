#include <stdio.h>
int main() {
    int ar[51][3] = {0,}; // 0 = 키, 1 = 몸무게, 2 = 덩치 등수
    
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    scanf("%d %d", &ar[i][0], &ar[i][1]);
    
    
    for(int i = 0; i < n; i++) {
        ar[i][2]++;
        for(int j = 0; j < n; j++) {
            if(i == j)
            continue;
            if(ar[i][0] < ar[j][0] && ar[i][1] < ar[j][1])
            ar[i][2]++;
        }    
    }
    
    for(int i = 0; i < n; i++)
    printf("%d ", ar[i][2]);
    return 0;
}