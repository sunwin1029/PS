#include <bits/stdc++.h>
#define TYPE pair <int, int>
using namespace std;

int n, l, r;
vector <vector <int>> board;
int drow[4] = {-1, 1, 0, 0}; // 상하좌우
int dcol[4] = {0, 0, -1, 1};


bool move() {
    bool isMove = false;
    vector <vector <bool>> groupComplete(n, vector <bool>(n, 0)); // 해당 위치가 이미 국경 이동이 완료된 그룹인지 확인

    queue <TYPE> q;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(groupComplete[i][j]) continue; // 이미 국경 이동이 완료된 경우

            int groupTotal = board[i][j]; // 해당 그룹의 값의 총 합계
            int groupAmt = 1; // 그룹에 속하는 국가의 수
            vector <TYPE> groupTable; // 해당 연합의 원본값 저장
            groupTable.push_back({i, j});
            q.push({i, j});
            groupComplete[i][j] = true;

            // 그룹 탐색
            while(!q.empty()) {
                TYPE tmp = q.front();
                q.pop();

                for(int i = 0; i < 4; i++) {
                    int newRow = tmp.first + drow[i];
                    int newCol = tmp.second + dcol[i];

                    if(newRow < 0 || newRow >= n || newCol < 0 || newCol >= n || groupComplete[newRow][newCol]) {
                        continue;
                    }

                    // 두 국가가 연합이 될 경우
                    int dif = abs(board[tmp.first][tmp.second] - board[newRow][newCol]);
                    if(dif >= l && dif <= r) {
                        groupAmt++;
                        groupTotal += board[newRow][newCol];
                        groupTable.push_back({newRow, newCol});
                        groupComplete[newRow][newCol] = true;
                        q.push({newRow, newCol});
                    }
                }
            }

            int afterShareVal  = groupTotal / groupAmt;

            for(int i = 0; i < groupAmt; i++) {
                int r = groupTable[i].first;
                int c = groupTable[i].second;

                if(board[r][c] != afterShareVal) {
                    board[r][c] = afterShareVal;
                    isMove = true;
                }
            }

        }
    }

    return isMove;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> l >> r;
    board.resize(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    int res = 0;

    while(true) {
        if(!move()) break;
        res++;
    }

    cout << res << "\n";

    return 0;
}