#include <bits/stdc++.h>
using namespace std;

int n, m;
int startPoint, endPoint;

struct Compare {
    bool operator() (const pair <int, int> &a, const pair <int, int> &b) const {
        return a.second > b.second;
    }
};

vector <pair <int, int>> road[1010];
vector <int> minDistance(1010, INT_MAX);
priority_queue<pair <int, int>, vector <pair <int, int>>, Compare> pq; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int start, end, weight;
    for(int i = 0; i < m; i++) {
        cin >> start >> end >> weight;
        road[start].push_back({end, weight});
    }
    cin >> startPoint >> endPoint;

    pq.push({startPoint, 0});
    minDistance[startPoint] = 0;

    while(!pq.empty()) {
        pair <int, int> tmp = pq.top();
        pq.pop();
        //if (tmp.second > minDistance[tmp.first]) continue;
        
        for(int i = 0; i < road[tmp.first].size(); i++) {
            int next = road[tmp.first][i].first;
            int weight = road[tmp.first][i].second;
            if(minDistance[next] > weight + minDistance[tmp.first]) {
                minDistance[next] = weight + minDistance[tmp.first];
                pq.push({next, minDistance[next]});
            }
        }
    }

    cout << minDistance[endPoint] << "\n";

    return 0;
}