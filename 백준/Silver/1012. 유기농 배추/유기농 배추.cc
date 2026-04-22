#include <bits/stdc++.h>
using namespace std;
void f() {
    int field[55][55] = {0,};
    bool v[55][55] = {0,};
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int cnt = 0;

    queue <pair<int, int>> Q;
    queue <pair<int, int>> container;
    int m, n, k; cin >> m >> n >> k;
    pair<int, int> p;
    for(int i = 0; i < k; i++) {
        int x, y; cin >> x >> y;
        field[x][y] = 1;
        container.push({x, y});
    }
    while(!container.empty()) {
        pair<int, int> tmp = container.front();
        container.pop();
        if(v[tmp.first][tmp.second] == true) continue;
        v[tmp.first][tmp.second] = true; 
        Q.push(tmp);
        while(!Q.empty()) {
            pair <int, int> cur = Q.front(); Q.pop();
            for(int dir = 0; dir < 4; dir++) {
                int x2 = cur.first + dx[dir];
                int y2 = cur.second + dy[dir];
                if(x2 < 0 || y2 < 0 || x2 >= m || y2 >= n) continue; 
                if(v[x2][y2] || field[x2][y2] != 1) continue;
                v[x2][y2] = 1;
                Q.push({x2, y2});
            }
        }
        cnt++;
    }
    cout << cnt << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for(int i = 0; i < t; i++) f();
    return 0;
}