#include <bits/stdc++.h>
using namespace std;

int n;
int drow[4] = {-1, 1, 0, 0};
int dcol[4] = {0, 0, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<vector<char>> board(n, vector<char>(n));

    for(int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;

        for(int j = 0; j < n; j++) {
            board[i][j] = tmp[j];
        }
    }

    vector<vector<bool>> normal_visited(n, vector<bool>(n, false));
    vector<vector<bool>> rg_visited(n, vector<bool>(n, false));

    int normal_res = 0;
    int rg_res = 0;

    queue<pair<int, int>> q1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!normal_visited[i][j]) {
                q1.push({i, j});
                normal_visited[i][j] = true;
                normal_res++;
                char color = board[i][j];

                while(!q1.empty()) {
                    pair<int, int> tmp = q1.front();
                    q1.pop();

                    for(int k = 0; k < 4; k++) {
                        int new_row = tmp.first + drow[k];
                        int new_col = tmp.second + dcol[k];

                        if(new_row < 0 || new_row >= n || new_col < 0 ||
                           new_col >= n)
                            continue;
                        if(normal_visited[new_row][new_col]) continue;
                        if(board[new_row][new_col] != color) continue;

                        normal_visited[new_row][new_col] = true;
                        q1.push({new_row, new_col});
                    }
                }
            } else {
                continue;
            }
        }
    }

    queue<pair<int, int>> q2;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!rg_visited[i][j]) {
                q2.push({i, j});
                rg_visited[i][j] = true;
                rg_res++;
                char color = board[i][j];

                while(!q2.empty()) {
                    pair<int, int> tmp = q2.front();
                    q2.pop();

                    for(int k = 0; k < 4; k++) {
                        int new_row = tmp.first + drow[k];
                        int new_col = tmp.second + dcol[k];

                        if(new_row < 0 || new_row >= n || new_col < 0 ||
                           new_col >= n)
                            continue;
                        if(rg_visited[new_row][new_col]) continue;

                        if(board[new_row][new_col] != color) {
                            if(!((color == 'R' || color == 'G') &&
                                 (board[new_row][new_col] == 'R' ||
                                  board[new_row][new_col] == 'G')))
                                continue;
                        }

                        rg_visited[new_row][new_col] = true;
                        q2.push({new_row, new_col});
                    }
                }
            } else {
                continue;
            }
        }
    }

    cout << normal_res << " " << rg_res << "\n";

    return 0;
}