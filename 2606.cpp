#include <bits/stdc++.h>
using namespace std;

int n, m;

vector <int> com[110];
bool is_virus[110];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int a, b;

    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        com[a].push_back(b);
        com[b].push_back(a);
    }

    queue <int> q;

    for(int i = 0; i < com[1].size(); i++) {
        q.push(com[1][i]);
    }

    while(!q.empty()) {
        int tmp = q.front();

        if(!is_virus[tmp]) {
            is_virus[tmp] = true;
            for(int i = 0; i < com[tmp].size(); i++) {
                q.push(com[tmp][i]);
            }
        }
        q.pop();
    }

    int res = 0;
    for(int i = 2; i <= n; i++) {
        if(is_virus[i]) res++;
    }

    cout << res << "\n";
    return 0;
}