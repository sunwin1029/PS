#include <bits/stdc++.h>
using namespace std;

int v, e;

struct Compare {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
        return a.second > b.second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> v >> e;
    vector<bool> visited(v + 10, false);
    vector<pair<int, int>> graph[10100];
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

    for(int i = 0; i < e; i++) {
        int ta, tb, tc;
        cin >> ta >> tb >> tc;

        graph[ta].push_back({tb, tc});
        graph[tb].push_back({ta, tc});
        if(ta == 1) {
            pq.push({tb, tc});
        }
        else if(tb == 1) {
            pq.push({ta, tc});
        }
    }

    int node_amt = 1;
    int res = 0;
    visited[1] = true;

    while(node_amt < v) {
        pair <int, int> tmp = pq.top();
        pq.pop();

        if(visited[tmp.first]) continue;
        node_amt++;
        res += tmp.second;
        visited[tmp.first] = true;

        for(int i = 0; i < graph[tmp.first].size(); i++) {
            pq.push(graph[tmp.first][i]);
        }
    }

    cout << res << "\n";

    return 0;
}