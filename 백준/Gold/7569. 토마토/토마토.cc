#include <bits/stdc++.h>
using namespace std;

int m, n, h;
int box[110][110][110]; // h, n, m
int cost[110][110][110];

int dx[6] = {0, 0, -1, 1, 0, 0}; // {위, 아래, 왼쪽, 오른쪽, 앞, 뒤}
int dy[6] = {0, 0, 0, 0, -1, 1};
int dz[6] = {1, -1, 0, 0, 0, 0};

queue <tuple <int, int, int, int>> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n >> h;

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                cin >> box[i][j][k];
                if(box[i][j][k] == 1)
                q.push({i, j, k, 0});
            }     
        }
    }

    while(!q.empty()) {
        tuple <int, int, int, int> tmp;
        tmp = q.front();

        for(int i = 0; i < 6; i++) {
            int height = get<0>(tmp) + dz[i];
            int row = get<1>(tmp) + dy[i];
            int column = get<2>(tmp) + dx[i];
            int day = get<3>(tmp) + 1;
            if(height >= 0 && height < h &&
                row >= 0 && row < n &&
                column >= 0 && column < m) {
                    if(box[height][row][column] == 0) {
                        q.push({height, row, column, day});
                        box[height][row][column] = 1;
                    }
                }
        }

        cost[get<0>(tmp)][get<1>(tmp)][get<2>(tmp)] = get<3>(tmp);

        q.pop();
    }

    int res = 0;
    bool not_complete = false;

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if(box[i][j][k] == 0) {
                    not_complete = true;
                }
                res = max(res, cost[i][j][k]);
            }
        }   
    }

    if(not_complete) cout << "-1\n";
    else cout << res << "\n";

    return 0;
}