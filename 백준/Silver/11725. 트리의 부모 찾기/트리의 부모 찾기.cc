#include <bits/stdc++.h>
using namespace std;

int n;

vector <int> tree[100100];
vector <int> parent(100100);


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n - 1; i++) {
        int start, des;

        cin >> start >> des;

        tree[start].push_back(des);
        tree[des].push_back(start);
    }

    queue <int> q;
    parent[1] = INT_MAX;
    q.push(1);

    while(!q.empty()) {
        int tmp = q.front();
        q.pop();

        for(int i = 0; i < tree[tmp].size(); i++) {
            if(parent[tree[tmp][i]] > 0) continue;
            else parent[tree[tmp][i]] = tmp;
            q.push(tree[tmp][i]);
        }
    }

    for(int i = 2; i <= n; i++) {
        cout << parent[i] << "\n";
    }

    return 0;
}