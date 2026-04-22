#include <stdio.h>

int cp(int a, int b) {
    return a < b ? a : b;
}
int main() {
    char board[51][51];
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        // for(int j = 0; j < m; j++)
        scanf("%s", &board[i]);
    }
    int min = 9999;
    int check = 0;
    int case_a = 0; // case w -> b
    int case_b = 0; // case b -> w
    for(int i = 0; i <= n - 8; i++) {
        for(int j = 0; j <= m - 8; j++) {
            check = (i + j) % 2;
            for(int y = i; y < i + 8; y++) {
                for(int x = j; x < j + 8; x++) {
                    if((x + y) % 2 == check) {
                        if(board[y][x] == 'W')
                        case_a++;
                        if(board[y][x] == 'B')
                        case_b++;
                    }
                    else {
                        if(board[y][x] == 'B')
                        case_a++;
                        if(board[y][x] == 'W')
                        case_b++;
                    }
                    
                }
            }
           min = cp(cp(case_a, case_b), min);
           case_b = 0;
           case_a = 0;
            
        }
    }
    printf("%d", min);

    return 0;
}