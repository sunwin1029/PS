#include <iostream>
using namespace std;
int n;
int num_color_paper[2]; // 0 -> white 1 -> blue
int arr[200][200];
void cut(int len, int x, int y) {
    int color = arr[y][x];
    int check = 0;
    for(int i = y; i < y + len; i++) {
        for(int j = x; j < x + len; j++)
        if(arr[i][j] != color) {
            check = 1;
            break;
        }
    }
    if(check == 0) {
        num_color_paper[color]++;
        return;
    }
    len /= 2;
    
    cut(len, x, y);
    cut(len, x + len, y);
    cut(len, x, y + len);
    cut(len, x + len, y + len);
    return;
}


int main() {
    //int arr[200][200] = {0,};
    //int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
        cin >> arr[i][j];
    }
    cut(n, 1, 1);
    cout << num_color_paper[0] << "\n";
    cout << num_color_paper[1];
    
    return 0;
}