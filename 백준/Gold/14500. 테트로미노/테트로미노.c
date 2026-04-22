#include <stdio.h>

int arr[510][510]; 

int cp(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n, m;
    int max = 0;
    int case_arr[20];
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
        scanf("%d", &arr[i][j]);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            case_arr[1] = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3];
            case_arr[2] = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 3][j];
            case_arr[3] = arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1];
            case_arr[4] = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j + 1];
            case_arr[5] = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 2];
            case_arr[6] = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
            case_arr[7] = arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i][j + 2];
            case_arr[8] = arr[i + 1][j] + arr[i + 1][j + 1] + arr[i][j + 2] + arr[i + 1][j + 2];
            case_arr[9] = arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j] + arr[i + 2][j + 1];
            case_arr[10] = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
            case_arr[11] = arr[i + 1][j] + arr[i + 1][j + 1] + arr[i][j + 1] + arr[i][j + 2];
            case_arr[12] = arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j] + arr[i + 2][j];
            case_arr[13] = arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
            case_arr[14] = arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
            case_arr[15] = arr[i][j + 1] + arr[i][j] + arr[i + 1][j] + arr[i + 2][j];
            case_arr[16] = arr[i][j + 1] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
            case_arr[17] = arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i][j + 2];
            case_arr[18] = arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
            case_arr[19] = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j];
            for(int k = 1; k <= 19; k++) {
                max = cp(max, case_arr[k]);
            }
        }
    }
    printf("%d", max);
    
    
    return 0;
}