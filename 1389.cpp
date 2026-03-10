#include <bits/stdc++.h>
using namespace std;

int kevin[110][110];
int res[110];
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == j) continue;
            kevin[i][j] = INT_MAX;
        }
    }

    for(int i = 0; i < m; i++) {
        int first;
        int second;

        cin >> first >> second;

        kevin[first][second] = 1;
        kevin[second][first] = 1;
    }

    // i = 경유, j = from, k = to
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            for(int k = 1; k <= n; k++) {
                if(k == j || i == k) continue;
                if(kevin[j][i] == INT_MAX || kevin[i][k] == INT_MAX) continue;
                if(kevin[j][k] > kevin[j][i] + kevin[i][k]) kevin[j][k] = kevin[j][i] + kevin[i][k];
            }
        }
    }

    int ans = INT_MAX;
    int num = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            res[i] += kevin[i][j];
        }
        if(ans > res[i]) num = i;
        ans = min(ans, res[i]);
    }

    cout << num << "\n";


    return 0;
}