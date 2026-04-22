#include <stdio.h>

int main() {
    int x, y;
    int passed_day = 0; // 1월 1일부터 며칠이 지났는지.
    
    
    scanf("%d %d", &x, &y);
    for(int i = 1; i < x; i++) {
        if(i == 2) {
            passed_day += 28;
            continue;
        }
        if(i < 8 && i % 2 == 1 || i >= 8 && i % 2 == 0) {
            passed_day += 31;
            continue;
        }
        passed_day += 30;
    }
    
    passed_day += y - 1;
    
    
    switch(passed_day % 7) {
        case 0 :
            printf("MON");
            break;
        case 1 :
            printf("TUE");
            break;
        case 2 :
            printf("WED");
            break;
        case 3 :
            printf("THU");
            break;
        case 4 :
            printf("FRI");
            break;
        case 5 : 
            printf("SAT");
            break;
        case 6 :
            printf("SUN");
            break;
        
    }
    

    return 0;
}