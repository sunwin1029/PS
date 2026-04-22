#include <bits/stdc++.h>
using namespace std;

int n;
int edge[1010][1010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;

            if(tmp == 0) edge[i][j] = INT_MAX;
            else edge[i][j] = 1;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(edge[j][i] == INT_MAX || edge[i][k] == INT_MAX) continue;
                edge[j][k] = min(edge[j][k], edge[j][i] + edge[i][k]);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(edge[i][j] == INT_MAX) cout << "0 ";
            else cout << "1 ";
        }
        cout << "\n";
    }

    return 0;
}