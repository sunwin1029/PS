#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> board(22, vector<int>(22, 0));

int n;
int shark_size = 2;  // 상어의 현재 크기
int eat_status = 0;  // 상어가 먹은 물고기 수
int res = 0;         // 결과

int drow[4] = {-1, 0, 1, 0};  // 상, 좌, 하, 우
int dcol[4] = {0, -1, 0, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    pair<int, int> shark_location;  // 상어의 위치 정보 저장

    // 공간 채우기
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            // 아기상어의 위치는 저장
            if(board[i][j] == 9) {
                shark_location = {i, j};
                board[i][j] = 0;
            }
        }
    }

    while(true) {
        queue<tuple<int, int, int>> q;

        // 상어가 방문했는지 확인하는 배열
        vector<vector<bool>> visited(22, vector<bool>(22, false));

        // 상어가 먹을 수 있는 물고기가 있는지 확인하는 변수
        bool is_possible_eat = false;

        // tmp값
        int new_row, new_col, new_time;

        // 최단거리로 물고기 1마리를 먹기 위한 값들을 저장
        int best_row, best_col, best_time;

        // 초기화
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

                // index 벗어남
                if(new_row < 0 || new_row >= n || new_col < 0 || new_col >= n)
                    continue;

                // 이미 방문한 위치 or 더 큰 물고기 존재
                if(visited[new_row][new_col] ||
                   board[new_row][new_col] > shark_size)
                    continue;

                visited[new_row][new_col] = true;

                // 먹을 수 있는 물고기인 경우
                if(board[new_row][new_col] != 0 &&
                   board[new_row][new_col] != shark_size) {
                    is_possible_eat = true;
                    // 현재 존재하는 최적수와 비교
                    if(best_time >= new_time) {
                        if(new_row < best_row ||
                           (new_row == best_row && new_col < best_col)) {
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

        board[best_row][best_col] = 0; // 먹은 물고기는 빈공간으로

        // 상어가 크기만큼 물고기를 잡아먹어 크기가 증가
        if(shark_size == eat_status) {
            eat_status = 0;
            shark_size++;
        }
        // 결과 추가
        res += best_time;
        // 상어 위치 업데이트  
        shark_location = {best_row, best_col};
    }

    cout << res << "\n";

    return 0;
}