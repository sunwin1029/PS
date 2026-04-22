#include <bits/stdc++.h>
using namespace std;

int n, m;
double D[60];
vector <int> G[55];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    D[1] = 100;

    for(int i = 1; i <= m; i++) {
        int s, e; cin >> s >> e;
        G[s].push_back(e);
    }
    for(int i = 1; i <= n; i++) {
        if(G[i].empty()) continue;
        double nxt = D[i] / G[i].size();
        for(auto j : G[i]) D[j] += nxt;
        D[i] = 0;

    }
    cout << fixed << setprecision(20) << *max_element(D + 1, D + n + 1);
    return 0;
}