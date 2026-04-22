#include <bits/stdc++.h>
using namespace std;

vector <vector <char>> arr(10010, vector<char>(10010, ' '));

void draw(int r, int c, int size) {
    if(size == 3) {
        arr[r][c] = '*';
        arr[r + 1][c - 1] = '*';
        arr[r + 1][c + 1] = '*';

        for(int i = 0; i < 5; i++) {
            arr[r + 2][c - 2 + i] = '*';
        }
        return;
    }

    draw(r, c, size / 2);
    draw(r + size / 2, c - size / 2, size / 2);
    draw(r + size / 2, c + size / 2, size / 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    draw(0, n - 1, n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n * 2 - 1; j++)
        cout << arr[i][j];

        cout << "\n";
    }

    return 0;
}