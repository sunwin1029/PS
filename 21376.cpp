#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[1000][1000];
bool visited[1000][1000];

int drow[4] = {-1, 1, 0, 0};  // 상 하 좌 우
int dcol[4] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    pair<int, int> start_point;
    queue<pair<int, int>> q;
    int res = 0;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for(int j = 0; j < m; j++) {
            board[i][j] = s[j];
            if(s[j] == 'I') start_point = {i, j};
        }
    }

    q.push(start_point);
    visited[start_point.first][start_point.second] = true;

    while(!q.empty()) {
        pair<int, int> tmp = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int new_row = tmp.first + drow[i];
            int new_col = tmp.second + dcol[i];

            if(new_row < 0 || new_row >= n || new_col < 0 || new_col >= m)
                continue;
            if(board[new_row][new_col] == 'X' || visited[new_row][new_col])
                continue;
            if(board[new_row][new_col] == 'P') res++;

            visited[new_row][new_col] = true;
            q.push({new_row, new_col});
        }
    }

    if(res == 0)
        cout << "TT\n";
    else {
        cout << res << "\n";
    }

    return 0;
}