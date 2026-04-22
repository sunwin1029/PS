#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> board(22, vector<int>(22, 0));

int n;
int shark_size = 2;
int eat_status = 0;
int res = 0;

int drow[4] = {-1, 0, 1, 0};  // 상, 좌, 하, 우
int dcol[4] = {0, -1, 0, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    pair<int, int> shark_location;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            if(board[i][j] == 9) {
                shark_location = {i, j};
                board[i][j] = 0;
            }
        }
    }

    while(true) {
        queue<tuple<int, int, int>> q;
        vector<vector<bool>> visited(22, vector<bool>(22, false));
        bool is_possible_eat = false;
        int new_row, new_col, new_time;
        int best_row, best_col, best_time;
        best_row = 22;
        best_col = 22;
        best_time = INT_MAX;

        visited[shark_location.first][shark_location.second] = true;
        q.push({shark_location.first, shark_location.second, 0});

        while(!q.empty()) {
            tuple<int, int, int> tmp = q.front();
            q.pop();
            new_time = get<2>(tmp) + 1;

            for(int i = 0; i < 4; i++) {
                new_row = get<0>(tmp) + drow[i];
                new_col = get<1>(tmp) + dcol[i];

                if(new_row < 0 || new_row >= n || new_col < 0 || new_col >= n)
                    continue;
                if(visited[new_row][new_col] ||
                   board[new_row][new_col] > shark_size)
                    continue;

                visited[new_row][new_col] = true;

                if(board[new_row][new_col] != 0 && board[new_row][new_col] != shark_size) {
                    is_possible_eat = true;
                    if(best_time >= new_time) {
                        if(new_row < best_row || (new_row == best_row && new_col < best_col)) {
                            best_row = new_row;
                            best_col = new_col;
                            best_time = new_time;
                        }
                    }
                }
                q.push({new_row, new_col, new_time});
            }

        }

        if(is_possible_eat)
            eat_status++;
        else {
            break;
        }

        board[best_row][best_col] = 0;
        if(shark_size == eat_status) {
            eat_status = 0;
            shark_size++;
        }
        res += best_time;
        shark_location = {best_row, best_col};
    }

    cout << res << "\n";

    return 0;
}