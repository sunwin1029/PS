#include <bits/stdc++.h>
using namespace std;

int loc[1010][1010];
int v[1010][1010];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    queue<pair<int, int>> Q;
    cin >> n >> m;

    pair<int, int> start;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int x;
            cin >> x;
            if(x == 2) start = make_pair(i, j);
            loc[i][j] = x;
        }
    }

    memset(v, -1, sizeof(v)); 
    Q.push(start);
    v[start.first][start.second] = 0; 

    while(!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int x = cur.first + dx[dir];
            int y = cur.second + dy[dir];
            if(x < 0 || y < 0 || x >= n || y >= m) continue; 
            if(v[x][y] != -1 || loc[x][y] == 0) continue;
            v[x][y] = v[cur.first][cur.second] + 1;
            Q.push({x, y});
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(loc[i][j] == 0)
                cout << 0 << " "; 
            else if(v[i][j] == -1)
                cout << -1 << " "; 
            else
                cout << v[i][j] << " "; 
        }
        cout << "\n";
    }

    return 0;
}