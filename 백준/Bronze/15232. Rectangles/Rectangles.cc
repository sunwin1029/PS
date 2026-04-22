#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int row, col;

    cin >> row >> col;


    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << "*";
        }
        cout << "\n";
    }


    return 0;
}