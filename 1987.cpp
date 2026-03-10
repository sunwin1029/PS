#include <bits/stdc++.h>
using namespace std;

vector <vector <int>> board(25, vector<int>(25));
int r, c;
int res = 1;
bool alphabet[27];

int dx[4] = {0, 0, -1, 1}; // 상 하 좌 우
int dy[4] = {-1, 1, 0, 0}; // 상 하 좌 우

/*
bool isReverse(int i, int prev) {
    if(i == 0 && prev == 1) return true;
    if(i == 1 && prev == 0) return true;
    if(i == 2 && prev == 3) return true;
    if(i == 3 && prev == 2) return true;

    return false;
} */

void f(int row, int column, int prev, int amt) {
    int new_row;
    int new_column;

    for(int i = 0; i < 4; i++) {
        // if(isReverse(i, prev)) continue;
        new_row = row + dy[i];
        new_column = column + dx[i];

        if(new_row < 0 || new_column < 0 || new_row >= r || new_column >= c) continue;
        char c = board[new_row][new_column];
        
        if(alphabet[c - 'A']) continue;
        else {
            res = res > amt + 1 ? res : amt + 1;
            alphabet[c - 'A'] = true;
            f(new_row, new_column, i, amt + 1);
            alphabet[c - 'A'] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c;

    for(int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < c; j++) {
            board[i][j] = s[j];
        }
    }

    alphabet[board[0][0] - 'A'] = true;
    f(0, 0, -1, 1);

    cout << res << "\n";

    return 0;
}