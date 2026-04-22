#include <bits/stdc++.h>
using namespace std;

int n;
vector <pair <int, int>> tree[10100]; // {destination, weight}

pair <int, int> bfs(int point) {
    queue <pair <int, int>> q;

    int dist_from_point[10100];

    fill(dist_from_point, dist_from_point + 10100, -1);

    q.push({point, 0});

    while(!q.empty()) {
        pair <int, int> tmp;
        tmp = q.front();

        dist_from_point[tmp.first] = tmp.second; // 거리 등록

        for(int i = 0; i < tree[tmp.first].size(); i++) {
            int next = tree[tmp.first][i].first;
            if(dist_from_point[next] < 0) {
                q.push({next, tmp.second + tree[tmp.first][i].second});
            }
        }
        q.pop();
    }

    int max = 0;
    int res = 0;
    for(int i = 1; i <= n; i++) {
        if(max < dist_from_point[i]) {
            max = dist_from_point[i];
            res = i;
        }
    }

    return {res, max};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n;

    for(int i = 0; i < n - 1; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;

        tree[from].push_back({to, weight});
        tree[to].push_back({from, weight});
    }

    pair <int, int> tmp = bfs(1);
    cout << bfs(tmp.first).second << "\n";

    return 0;
}