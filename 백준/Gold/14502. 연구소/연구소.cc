#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10][10];

int bfs() {
    queue <pair <int, int>> q;
    int safe_area = 0;
    int tmp[10][10];
    memcpy(tmp, arr, sizeof(arr));


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(tmp[i][j] == 2) {
                q.push({i, j});
            }
        }
    }

    while(!q.empty()) {
        pair <int, int> p = q.front();
        if(p.first > 0 && tmp[p.first - 1][p.second] == 0) {
            tmp[p.first - 1][p.second] = 2;
            q.push({p.first - 1, p.second});
        }
        if(p.first < n - 1 && tmp[p.first + 1][p.second] == 0) {
            tmp[p.first + 1][p.second] = 2;
            q.push({p.first + 1, p.second});
        }
        if(p.second > 0 && tmp[p.first][p.second - 1] == 0) {
            tmp[p.first][p.second - 1] = 2;
            q.push({p.first, p.second - 1});
        }
        if(p.second < m - 1 && tmp[p.first][p.second + 1] == 0) {
            tmp[p.first][p.second + 1] = 2;
            q.push({p.first, p.second + 1});
        }
        q.pop();
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(tmp[i][j] == 0)
            safe_area++;
        }
    }

    return safe_area;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int res = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
        cin >> arr[i][j];
    }

    for(int i = 0; i < n * m - 2; i++) {
        if(arr[i / m][i % m] != 0) continue;
        arr[i / m][i % m] = 1;

        for(int j = i + 1; j < n * m - 1; j++) {
            if(arr[j / m][j % m] != 0) continue;
            arr[j / m][j % m] = 1;

            for(int k = j + 1; k < n * m; k++) {
                if(arr[k / m][k % m] != 0) continue;
                arr[k / m][k % m] = 1;

                res = max(res, bfs());

                arr[k / m][k % m] = 0;
            }

            arr[j / m][j % m] = 0;
        }

        arr[i / m][i % m] = 0;
    }

    cout << res << "\n";

    return 0;
}