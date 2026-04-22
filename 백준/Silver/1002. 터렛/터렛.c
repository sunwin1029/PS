 #include <stdio.h>
#include <math.h>

int main() {
    int x1, x2, y1, y2, r1, r2;
    int n;
    
    double dis;
    double dis_2; /// 규현, 승환 사거리(원의 반지름)의 합;
    double dis_3; /// 
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        dis = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        dis_2 = r1 + r2;
        dis_3 = r1 > r2 ? r1 - r2 : r2 - r1; // 두 반지름의 차
        //printf("dis : %d\n", dis);
        //printf("dis_2 : %d\n", dis_2);
        //printf("dis_3 : %d\n", dis_3);
        if(dis == 0 && r1 == r2) {
            printf("-1\n");
        }
        else if((dis < r1 + r2) && (dis_3 < dis)) {
            printf("2\n");
        }
        else if(dis == r1 + r2 || dis == dis_3) {
            printf("1\n");
        }
        else
        printf("0\n");
    }
    
    return 0;
} 