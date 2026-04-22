#include <bits/stdc++.h>
using namespace std;

int n, m;
long long res = 0;
int arr[1010][1010];

int drow[4] = {-1, 1, 0, 0}; // 상, 하, 좌, 우
int dcol[4] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    queue <pair <int, int>> q;
    int min_val = INT_MAX;
    pair <int, int> min_loc;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int tmp;
            cin >> tmp;
            if(tmp < min_val) {
                min_val = tmp;
                min_loc = {i, j};
            }
            if(tmp == 0) q.push({i, j});
            arr[i][j] = tmp;
        }
    }

    if(q.empty()) {
        // res += min_val;
        arr[min_loc.first][min_loc.second] = 0;
        q.push(min_loc);
    }

    while(!q.empty()) {
        pair <int, int> tmp = q.front();
        int row, col;
        q.pop();

        for(int i = 0; i < 4; i++) {
            row = tmp.first + drow[i];
            col = tmp.second + dcol[i];

            if(row < 0 || col < 0 || row >= n || col >= m) continue;
            if(arr[row][col] == 0) continue;

            res += arr[row][col];
            arr[row][col] = 0;
            q.push({row, col});
        }
    }

    cout << res << "\n";
    
    return 0;
}