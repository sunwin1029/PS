#include <bits/stdc++.h>
using namespace std;

int tc;

void f() {
    int n, m, w;
    int s, e, t;
    vector<tuple<int, int, int>> road;

    cin >> n >> m >> w;
    vector<int> dis(3000, 0);

    for (int i = 0; i < m; i++) {
        cin >> s >> e >> t;
        road.push_back({s, e, t});
        road.push_back({e, s, t});
    }
    for (int i = 0; i < w; i++) {
        cin >> s >> e >> t;
        road.push_back({s, e, -t});
    }

    // 벨만-포드 알고리즘으로 최단거리 확인
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < road.size(); j++) {
            int start, end, weight;
            start = get<0>(road[j]);
            end = get<1>(road[j]);
            weight = get<2>(road[j]);

            if (dis[start] == INT_MAX) continue;

            if (dis[end] > dis[start] + weight) {
                dis[end] = dis[start] + weight;
            }
        }
    }

    bool is_infinite = false;
    // 음수 사이클이 존재하는지 확인
    for (int i = 0; i < road.size(); i++) {
        int start, end, weight;
        start = get<0>(road[i]);
        end = get<1>(road[i]);
        weight = get<2>(road[i]);


        if (dis[end] > dis[start] + weight) {
            is_infinite = true;
        }
    }

    cout << (is_infinite ? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> tc;
    while (tc--) f();

    return 0;
}