#include <bits/stdc++.h>
#define BLACK -1
#define RAINBOW 0
#define EMPTY -2
using namespace std;

int n, m;
vector<vector<int>> board;
int drow[4] = {-1, 1, 0, 0};  // 상, 하, 좌, 우
int dcol[4] = {0, 0, -1, 1};
int res = 0;

void rotate();
bool play();
void gravity();
void deleteBlock(tuple<int, int, int, int>& t);

bool Compare(const tuple<int, int, int, int>& a,
             const tuple<int, int, int, int>& b) {
    if(get<2>(a) == get<2>(b)) {
        if(get<3>(a) == get<3>(b)) {
            if(get<0>(a) == get<0>(b)) {
                return get<1>(a) > get<1>(b);
            }
            return get<0>(a) > get<0>(b);
        }
        return get<3>(a) > get<3>(b);
    }

    return get<2>(a) > get<2>(b);
}

bool play() {
    vector<tuple<int, int, int, int>>
        groupStandard;  // {row, col, size, rainbowAmt}
    vector<vector<bool>> isGroup(n, vector<bool>(n, false));

    for(int r = 0; r < n; r++) {
        for(int c = 0; c < n; c++) {
            int finalR = r;
            int finalC = c;

            vector<vector<bool>> visited(n, vector<bool>(n, false));
            // 이미 해당 위치가 그룹에 속한 경우, 검정색 블록, 무지개 블록인
            // 경우
            if(isGroup[r][c] || board[r][c] == BLACK || board[r][c] == RAINBOW || board[r][c] == EMPTY)
                continue;

            // BFS
            queue<pair<int, int>> q;

            // 초기 세팅
            int color = board[r][c];
            int groupSize = 1;
            int rainbowAmt = 0;

            visited[r][c] = true;
            isGroup[r][c] = true;
            q.push({r, c});

            while(!q.empty()) {
                pair<int, int> tmp = q.front();
                q.pop();

                for(int i = 0; i < 4; i++) {
                    int newRow = tmp.first + drow[i];
                    int newCol = tmp.second + dcol[i];

                    if(newRow < 0 || newRow >= n || newCol < 0 || newCol >= n ||
                       visited[newRow][newCol]) {
                        continue;
                    }

                    // 무지개색 블록의 다른 그룹에서도 사용 가능하니까 따로 처리
                    if(board[newRow][newCol] == RAINBOW) {
                        groupSize++;
                        rainbowAmt++;
                        visited[newRow][newCol] = true;
                        q.push({newRow, newCol});
                        continue;
                    }

                    if(board[newRow][newCol] != color ||
                       board[newRow][newCol] == BLACK) {
                        continue;
                    }

                    groupSize++;
                    visited[newRow][newCol] = true;
                    q.push({newRow, newCol});
                    isGroup[newRow][newCol] = true;

                    if(newRow == finalR) {
                        if(newCol < finalC) {
                            finalC = newCol;
                        }
                    } else if(newRow < finalR) {
                        finalR = newRow;
                        finalC = newCol;
                    }
                }
            }

            if(groupSize < 2) {
                continue;
            } else {
                groupStandard.push_back(
                    {finalR, finalC, groupSize, rainbowAmt});
            }
        }
    }

    // 오토 플레이가 불가능해짐
    if(groupStandard.size() == 0) return false;

    // 가장 큰 블록 그룹 찾기
    sort(groupStandard.begin(), groupStandard.end(), Compare);

    // 해당 그룹의 블록 지우기
    deleteBlock(groupStandard[0]);

    // 중력 적용
    gravity();

    // 반시계 방향 회전
    rotate();

    // 중력 적용
    gravity();

    return true;
}

void deleteBlock(tuple<int, int, int, int>& t) {
    int deletedAmt = 0;
    queue<pair<int, int>> q;
    int color = board[get<0>(t)][get<1>(t)];
    q.push({get<0>(t), get<1>(t)});
    board[get<0>(t)][get<1>(t)] = EMPTY;

    while(!q.empty()) {
        pair<int, int> tmp = q.front();
        q.pop();
        deletedAmt++;

        for(int i = 0; i < 4; i++) {
            int newRow = tmp.first + drow[i];
            int newCol = tmp.second + dcol[i];

            if(newRow < 0 || newRow >= n || newCol < 0 || newCol >= n) {
                continue;
            }
            if(board[newRow][newCol] == color ||
               board[newRow][newCol] == RAINBOW) {
                board[newRow][newCol] = EMPTY;
                q.push({newRow, newCol});
            }
        }
    }

    res += deletedAmt * deletedAmt;
}

void gravity() {
    for(int c = 0; c < n; c++) {
        int bottomPoint = n - 1;

        for(int r = n - 1; r >= 0; r--) {
            if(board[r][c] == BLACK) {
                bottomPoint = r - 1;
                continue;
            }
            if(board[r][c] != EMPTY) {
                // 내려갈 공간이 없는 경우
                if(bottomPoint <= r) {
                    bottomPoint = r - 1;
                    continue;
                }

                // 내려갈 공간이 있는 경우
                board[bottomPoint][c] = board[r][c];
                bottomPoint--;

                board[r][c] = EMPTY;
            }
        }
    }
}

void rotate() { 
    vector<vector<int>> tmpBoard(n, vector<int>(n)); 

    for(int r = 0; r < n; r++) {
        for(int c = 0; c < n; c++) {
            tmpBoard[n - 1 - c][r] = board[r][c];
        }
    }

    board = tmpBoard;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    board.resize(n, vector<int>(n));

    for(int r = 0; r < n; r++) {
        for(int c = 0; c < n; c++) {
            cin >> board[r][c];
        }
    }
    
    while(play()) {
    }

    cout << res << "\n";

    return 0;
}