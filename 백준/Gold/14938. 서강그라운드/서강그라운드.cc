#include <bits/stdc++.h>
using namespace std;

int n, m, r;
vector <int> items(110, 0);

vector <vector <int>> short_dis(110, vector<int>(110, INT_MAX));


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> r;

    for(int i = 1; i <= n; i++) cin >> items[i];

    for(int i = 1; i <= n; i++) {
        short_dis[i][i] = 0;
    }


    for(int i = 1; i <= r; i++) {
        int start, des, cost;
        
        cin >> start >> des >> cost;
        short_dis[start][des] = cost;
        short_dis[des][start] = cost;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                if(short_dis[j][i] != INT_MAX && short_dis[i][k] != INT_MAX) {
                    short_dis[j][k] = min(short_dis[j][k], short_dis[j][i] + short_dis[i][k]);
                }
            }
        }
    }

    int max_res = 0;
    int tmp_res = 0;

    for(int i = 1; i <= n; i++) {
        tmp_res = 0;
        for(int j = 1; j <= n; j++) {
            if(short_dis[i][j] <= m) tmp_res += items[j];
        }

        max_res = max(max_res, tmp_res);
    }
    cout << max_res << "\n";

    return 0;
}