#include <stdio.h>
#include <string.h>

int main() {
    char arr[15];
    int t = 0; // t == time;
    scanf("%s", arr);
    int len = strlen(arr);
    for(int i = 0; i < len; i++) {
        int c = arr[i];
        if(c >= 65 && c <= 67)
        t += 3; // 2(ABC)
        else if(c >= 68 && c <= 70)
        t += 4; // 3(DEF)
        else if(c >= 71 && c <= 73)
        t += 5; // 4(GHI)
        else if(c >= 74 && c <= 76)
        t += 6; // 5(JKL)
        else if(c >= 77 && c <= 79)
        t += 7; // 6(MNO)
        else if(c >= 80 && c <= 83)
        t += 8; // 7(PQRS)
        else if(c >= 84 && c <= 86)
        t += 9; // 8(TUV)
        else if(c >= 87 && c <= 90)
        t += 10; // 9(WXYZ)
    }
    printf("%d", t);

    return 0;
}