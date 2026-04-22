#include <bits/stdc++.h>
using namespace std;

int n, m, in[1010], dp[1010];
vector <int> G[1010];
queue <int> Q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int s, e; cin >> s >> e;
        G[s].push_back(e);
        in[e]++;
    }
    for(int i = 1; i <= n; i++) {
        if(!in[i]) {
            Q.push(i);
            dp[i] = 1;
        }
    }
    while(!Q.empty()) {
        int x = Q.front(); Q.pop();
        for(auto i : G[x] ) {
            dp[i] = max(dp[i], dp[x] + 1);
            if(!--in[i]) Q.push(i);
        }
    }
    for(int i = 1; i <= n; i++) cout << dp[i] << " ";
    return 0;
}