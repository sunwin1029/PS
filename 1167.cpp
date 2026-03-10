#include <bits/stdc++.h>
using namespace std;

vector <pair <int, int>> tree[100100];
int n;

pair <int, int> bfs(int point) {
    queue <pair <int, int>> q; // {destination, weight}

    int weight[100100];
    fill(weight, weight + 100100, -1);

    q.push({point, 0});

    while(!q.empty()) {
        pair <int, int> tmp;
        tmp = q.front();

        weight[tmp.first] = tmp.second;

        for(int i = 0; i < tree[tmp.first].size(); i++) {
            if(weight[tree[tmp.first][i].first] < 0) {
                q.push({tree[tmp.first][i].first, tree[tmp.first][i].second + tmp.second});
            }
        }

        q.pop();
    }

    int max = 0;
    int res_point;
    for(int i = 1; i <= n; i++) {
        if(weight[i] > max) {
            max = weight[i];
            res_point = i;
        }
    }

    return {res_point, max};
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++) {
        int point;
        cin >> point;

        int destination, weight;

        while(true) {
            cin >> destination;
            if(destination == -1) break;

            cin >> weight;
            tree[point].push_back({destination, weight});
            // tree[destination].push_back({point, weight});
        }
    }

    cout << bfs(bfs(1).first).second << "\n";


    return 0;
}