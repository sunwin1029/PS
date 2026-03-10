#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> board(110, vector<int>(110));
vector<vector<int>> air(110, vector<int>(110));
int drow[4] = {-1, 1, 0, 0};  // 상, 하, 좌, 우
int dcol[4] = {0, 0, -1, 1};
int hour = 0;
int cheese_amt = 0;

void get_out_air() {
    for(int i = 0; i < 110; i++) {
        for(int j = 0; j < 110; j++) air[i][j] = 0;
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    air[0][0] = 1;

    while(!q.empty()) {
        pair<int, int> tmp = q.front();
        q.pop();
        int row, col;

        for(int i = 0; i < 4; i++) {
            row = tmp.first + drow[i];
            col = tmp.second + dcol[i];

            if(row < 0 || row >= n || col < 0 || col >= m) continue;
            if(air[row][col] < 1 && board[row][col] < 1) {
                air[row][col] = 1;
                q.push({row, col});
            }
        }
    }
}

void make_air() {
    hour--;

    vector<pair<int, int>> store;
    for(int i = 1; i < n - 1; i++) {
        for(int j = 1; j < m - 1; j++) {
            if(board[i][j] < 1) continue;
            int air_amt = 0;
            for(int k = 0; k < 4; k++) {
                if(air[i + drow[k]][j + dcol[k]] > 0) air_amt++;
            }
            if(air_amt > 1) store.push_back({i, j});
        }
    }
    for(int i = 0; i < store.size(); i++) {
        pair<int, int> tmp = store[i];
        board[tmp.first][tmp.second] = hour;
        cheese_amt--;
    }
}

void simulation() {
    bool all_air = false;
    while(cheese_amt > 0) {
        get_out_air();
        make_air();
    }
    int res = 0;
    cout << -hour << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 1) cheese_amt++;
        }
    }

    simulation();

    return 0;
}