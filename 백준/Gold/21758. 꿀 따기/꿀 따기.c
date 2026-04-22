#include <stdio.h>
int place[100001];
int bee_1;
int bee_2;
int honey_case;
int cp(int a, int b) {
    return a>b?a:b;
}
int main() {
    int n;
    int best = 0;
    int ex_1_best_case = 0;
    int ex_2_best_case = 0;
    int ex_3_best_case = 0;
    int ex_1 = 0;
    int ex_2 = 0;
    int ex_3 = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    scanf("%d", &place[i]);
   
    // 꿀벌이 양 끝인 경우
    for(int i = 1; i < n - 1; i++) {
        ex_1_best_case = cp(ex_1_best_case, place[i]);
    }
    for(int i = 1; i < n - 1; i++)
    ex_1 += place[i];
    ex_1 += ex_1_best_case;
    
    // 꿀통 ~ 꿀벌 ~ 꿀벌
    // /*
    
    int min_2;
    int min_place_2 = n - 2;
    int q_2 = place[n - 2] * 2;
    min_2 = q_2;
    for(int i = n - 3; i >= 1; i--) {
        q_2 += place[i] * 2 - place[i + 1];
        if(min_2 > q_2) {
            min_2 = q_2;
            min_place_2 = i;
        }
    }
    for(int i = n - 2; i >= 0; i--) {
        ex_2 += place[i];
    }
    ex_2 -= place[min_place_2];
    for(int i = min_place_2 - 1; i >= 0; i--) {
        ex_2 += place[i];
    }
    // */
    //꿀벌 ~ 꿀벌 ~ 꿀통
    // /*

    int min_3;
    int min_place_3 = 1;
    int q_3 = place[1] * 2;
    min_3 = q_3;
    for(int i = 2; i < n - 1; i++) {
        q_3 += place[i] * 2 - place[i - 1];
        if(min_3 > q_3) {
            min_3 = q_3;
            min_place_3 = i;
        }
    }
    for(int i = 1; i < n; i++) {
        ex_3 += place[i];
    }
    ex_3 -= place[min_place_3];
    for(int i = min_place_3 + 1; i < n; i++) {
        ex_3 += place[i];
    }
    
    // */
    int res = cp(cp(ex_1, ex_2), ex_3);
    printf("%d", res);
    // printf("%d %d %d %d", res, ex_1, ex_2, ex_3);
    
    
    
    return 0;
}