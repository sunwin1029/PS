#include <iostream>
using namespace std;
int n;
int arr[200][200];
void cut(int len, int x, int y) {
    int num = arr[y][x];
    int check = 0;
    for(int i = y; i < y + len; i++) {
        for(int j = x; j < x + len; j++)
        if(arr[i][j] != num) {
            check = 1;
            break;
        }
    }
    if(check == 0) {
        cout << num;
        return;
    }
    len /= 2;
    cout << "(";
    cut(len, x, y);
    cut(len, x + len, y);
    cut(len, x, y + len);
    cut(len, x + len, y + len);
    cout << ")";
    return;
}


int main() {
    cin >> n;
    string str;
    for(int i = 1; i <= n; i++) {
        cin >> str;
        for(int j = 1; j <= n; j++)
        arr[i][j] = str[j - 1] - '0';
    }
    
    cut(n, 1, 1);
    //cout << "check\n";
    return 0;
}