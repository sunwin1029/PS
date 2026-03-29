#include <bits/stdc++.h>
#define VIRUS 0
#define NOTACTIVATED -1
#define EMPTY -2
#define WALL -3
using namespace std;

int n, m;
int res = INT_MAX;
int emptySpace = 0;
int virusAmt = 0;
vector<vector<int>> board;
vector<pair<int, int>> virus;           // 비활성화된 바이러스
vector<pair<int, int>> activatedVirus;  // 활성화된 바이러스 기록
int drow[4] = {-1, 1, 0, 0};            // 상, 하, 좌, 우
int dcol[4] = {0, 0, -1, 1};

void bfs() {
    queue<pair<int, int>> q;               // bfs를 위한 큐
    vector<vector<int>> tmpBoard = board;  // 판 복사
    int tmpEmptySpace = emptySpace; // 남은 빈공간 수 복사
    int t = 0;  // 소모된 시간 평가

    // 활성화된 바이러스 넣기
    for(int i = 0; i < activatedVirus.size(); i++) {
        q.push(activatedVirus[i]);
        tmpBoard[activatedVirus[i].first][activatedVirus[i].second] =
            VIRUS;  // 활성화된 바이러스로 변경
    }

    while(!q.empty()) {
        pair<int, int> tmpVirus = q.front();  // BFS
        int virusTime = tmpBoard[tmpVirus.first][tmpVirus.second]; // 해당 바이러스 전파 시간 기록
        q.pop();
        // 4방향 바이러스 전파
        for(int i = 0; i < 4; i++) {
            // 새로 이동할 위치 지정
            int newRow = tmpVirus.first + drow[i];
            int newCol = tmpVirus.second + dcol[i];

            // 범위 검사
            if(newRow < 0 || newRow >= n || newCol < 0 || newCol >= n) {
                continue;
            }
            // 벽일 경우
            if(tmpBoard[newRow][newCol] == WALL) {
                continue;
            }
            // 빈공간에 바이러스 전파
            if(tmpBoard[newRow][newCol] == EMPTY) {
                tmpBoard[newRow][newCol] = virusTime + 1; // 시간 기록
                t = max(t, virusTime + 1); // 시간 검사
                q.push({newRow, newCol}); // 전파큐에 다시 넣기
                tmpEmptySpace--; // 빈 공간 수 감소
                continue;
            }
            // 비활성화 바이러스 만날 경우 (빈 공간이 아니니까 빈공간 수 감소시키면 안됨)
            if(tmpBoard[newRow][newCol] == NOTACTIVATED) {
                tmpBoard[newRow][newCol] = virusTime + 1;
                q.push({newRow, newCol});
            }
        }
    }

    if(tmpEmptySpace == 0) {
        res = min(res, t);
    }
}

void backTracking(int idx, int virusCnt) {
    if(virusCnt == m) {
        bfs();
        return;
    }
    for(int i = idx; i < virus.size(); i++) {
        activatedVirus.push_back(virus[i]);
        backTracking(i + 1, virusCnt + 1);
        activatedVirus.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    board.resize(n, vector<int>(n));

    // board에 바이러스 입력
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            if(board[i][j] == 2) {
                virus.push_back({i, j});
                virusAmt++;
                board[i][j] = NOTACTIVATED;
            }
            if(board[i][j] == 0) {
                board[i][j] = EMPTY;
                emptySpace++;
            }
            if(board[i][j] == 1) {
                board[i][j] = WALL;
            }
        }
    }

    if(emptySpace == 0) {
        cout << 0 << "\n";
        return 0;
    }

    backTracking(0, 0);

    cout << (res == INT_MAX ? -1 : res) << "\n";


    return 0;
}