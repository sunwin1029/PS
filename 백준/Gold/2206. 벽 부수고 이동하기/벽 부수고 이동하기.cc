#include <bits/stdc++.h>
using namespace std;

int n, m;
int drow[4] = {-1, 1, 0, 0};  // 상, 하, 좌, 우
int dcol[4] = {0, 0, -1, 1};

int maze[1010][1010];
vector<vector<vector<int>>> dis(1010,
                                vector<vector<int>>(1010,
                                                    vector<int>(2, INT_MAX)));

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) maze[i][j] = s[j] - '0';
    }

    queue<tuple<int, int, int>> q;
    dis[0][0][0] = 1;
    q.push({0, 0, 0});

    while(!q.empty()) {
        tuple<int, int, int> tmp =
            q.front();  // row, col, isBreak(벽을 부수고 왔는가?)
        q.pop();

        int row = get<0>(tmp);
        int col = get<1>(tmp);
        int isBreak = get<2>(tmp);

        for(int i = 0; i < 4; i++) {
            int newRow = row + drow[i];
            int newCol = col + dcol[i];

            if(newRow < 0 || newRow >= n || newCol < 0 || newCol >= m) continue;
            if(maze[newRow][newCol] == 1 && isBreak == 1) continue;
            if(maze[newRow][newCol] == 1 && isBreak == 0) {
                if(dis[newRow][newCol][1] > dis[row][col][isBreak] + 1) {
                    dis[newRow][newCol][1] = dis[row][col][isBreak] + 1;
                    q.push({newRow, newCol, 1});
                }
            } else if(maze[newRow][newCol] == 0) {
                if(dis[newRow][newCol][isBreak] > dis[row][col][isBreak] + 1) {
                    dis[newRow][newCol][isBreak] = dis[row][col][isBreak] + 1;
                    q.push({newRow, newCol, isBreak});
                }
            }
        }
    }

    if(dis[n - 1][m - 1][0] == INT_MAX && dis[n - 1][m - 1][1] == INT_MAX)
        cout << "-1\n";
    else
        cout << min(dis[n - 1][m - 1][0], dis[n - 1][m - 1][1]) << "\n";

    return 0;
}