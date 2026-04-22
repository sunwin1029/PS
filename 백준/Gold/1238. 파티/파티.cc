#include <bits/stdc++.h>
using namespace std;

int n, m, x;
// vector <pair <int, int>> road[1010]; // {destination, weight}
vector <vector <int>> dis(1010, vector<int>(1010, INT_MAX));

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> x;

    // 경로 road에 정리하기
    int start, des, weight;
    for(int i = 1; i <= m; i++) {
        cin >> start >> des >> weight;
        dis[start][des] = weight;
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            if(dis[i][k] == INT_MAX) continue;
            for(int j = 1; j <= n; j++) {
                if(i == j || dis[k][j] == INT_MAX) continue;
                if(dis[i][k] != INT_MAX && dis[k][j] != INT_MAX) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
    }

    long long res = 0;

    for(int i = 1; i <= n; i++) {
        if(i == x) continue;
        long long val = dis[i][x] + dis[x][i];
        res = res > val ? res : val;
    }

    cout << res << "\n";

    return 0;
}