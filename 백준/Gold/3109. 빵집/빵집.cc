#include <bits/stdc++.h>
using namespace std;

int r, c;
int res = 0;
stack<pair<int, int>> s;

bool dfs(vector<vector<int>>& board) {
    pair<int, int> p = s.top();
    board[p.first][p.second] = 'x';

    if(p.second == c - 1) {
        while(!s.empty()) {
            s.pop();
        }
        return true;
    }
    for(int i = -1; i < 2; i++) {
        int new_row = p.first + i;
        int new_col = p.second + 1;

        if(new_row < 0 || new_row >= r || board[new_row][new_col] == 'x')
            continue;
        else {
            s.push({new_row, new_col});
            if(dfs(board)) return true;
        }
    }
    s.pop();
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c;
    vector<vector<int>> board(r, vector<int>(c, 0));

    for(int i = 0; i < r; i++) {
        string tmp;
        cin >> tmp;
        for(int j = 0; j < c; j++) {
            board[i][j] = tmp[j];
        }
    }

    for(int i = 0; i < r; i++) {
        s.push({i, 0});
        if(dfs(board)) res++;
    }

    cout << res << "\n";

    return 0;
}