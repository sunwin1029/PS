#include <bits/stdc++.h>
using namespace std;

int n, e;

vector <vector<int>> road(880, vector<int>(880));

struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return a.second > b.second;
    }
};
priority_queue <pair<int, int>, vector<pair<int, int>>, Compare> pq; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> e;
    int v1, v2;

    for(int i = 1; i <= e; i++) {
        int start, end, weight;
        cin >> start >> end >> weight;

        road[start][end] = weight;
        road[end][start] = weight;
    }
    cin >> v1 >> v2;

    vector <int> dis_from_start(880, INT_MAX);
    dis_from_start[1] = 0;

    pq.push({1, 0});

    while(!pq.empty()) {
        pair <int, int> tmp = pq.top();
        pq.pop();

        for(int i = 1; i <= n; i++) {
            if(road[tmp.first][i] != 0 && tmp.second + road[tmp.first][i] < dis_from_start[i]) {
                dis_from_start[i] = tmp.second + road[tmp.first][i];
                pq.push({i, dis_from_start[i]});
            }
        }
    }

    vector <int> dis_from_v1(880, INT_MAX);
    dis_from_v1[v1] = 0;

    pq.push({v1, 0});

    while(!pq.empty()) {
        pair <int, int> tmp = pq.top();
        pq.pop();

        for(int i = 1; i <= n; i++) {
            if(road[tmp.first][i] != 0 && tmp.second + road[tmp.first][i] < dis_from_v1[i]) {
                dis_from_v1[i] = tmp.second + road[tmp.first][i];
                pq.push({i, dis_from_v1[i]});
            }
        }
    }

    vector <int> dis_from_v2(880, INT_MAX);
    dis_from_v2[v2] = 0;

    pq.push({v2, 0});

    while(!pq.empty()) {
        pair <int, int> tmp = pq.top();
        pq.pop();

        for(int i = 1; i <= n; i++) {
            if(road[tmp.first][i] != 0 && tmp.second + road[tmp.first][i] < dis_from_v2[i]) {
                dis_from_v2[i] = tmp.second + road[tmp.first][i];
                pq.push({i, dis_from_v2[i]});
            }
        }
    }
    int res1 = INT_MAX;
    int res2 = INT_MAX;

    if(dis_from_start[v1] != INT_MAX && dis_from_v1[v2] != INT_MAX && dis_from_v2[n] != INT_MAX)
        res1 = dis_from_start[v1] + dis_from_v1[v2] + dis_from_v2[n];
    if(dis_from_start[v2] != INT_MAX && dis_from_v2[v1] != INT_MAX && dis_from_v1[n] != INT_MAX)
        res2 = dis_from_start[v2] + dis_from_v2[v1] + dis_from_v1[n]; 

    if(res1 == INT_MAX && res2 == INT_MAX) cout << "-1\n";
    else cout << (res1 < res2 ? res1 : res2) << "\n";

    return 0;
}