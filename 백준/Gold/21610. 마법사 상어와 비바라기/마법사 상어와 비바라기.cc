#include <bits/stdc++.h>
#define EMPTY 0
#define CLOUD 1
using namespace std;

int n, m;
vector<vector<int>> board;
vector<vector<int>> cloud;
int drow[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dcol[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int diagRow[4] = {-1, -1, 1, 1};
int diagCol[4] = {-1, 1, 1, -1};

int getLoc(int x) {
    if(x >= 0) return x % n;
    else {
        while(x < 0) {
            x += n;
        }
    }
    return x % n;
}

void move(int d, int s) {
    // 새로운 구름의 위치 저장
    vector<vector<int>> newCloud(n, vector<int>(n, EMPTY));

    // 1. 구름의 이동
    for(int r = 0; r < n; r++) {
        for(int c = 0; c < n; c++) {
            if(cloud[r][c] == EMPTY) {
                continue;
            } else {
                int newRow = getLoc(r + drow[d] * s);
                int newCol = getLoc(c + dcol[d] * s);

                newCloud[newRow][newCol] = CLOUD;
            }
        }
    }

    // 기존의 비의 양을 저장할 배열
    vector<vector<int>> tmpBoard(n, vector<int>(n));
    tmpBoard = board;

    // 2. 비내리기
    for(int r = 0; r < n; r++) {
        for(int c = 0; c < n; c++) {
            if(newCloud[r][c] == CLOUD) {
                board[r][c]++;
            }
        }
    }

    // 3. 구름 삭제
    for(int r = 0; r < n; r++) {
        for(int c = 0; c < n; c++) {
            cloud[r][c] = EMPTY;
        }
    }

    for(int r = 0; r < n; r++) {
        for(int c = 0; c < n; c++) {
            // 4. 물이 증가한 경우, 비복사버그
            if(board[r][c] != tmpBoard[r][c]) {
                int diagWaterAmt = 0;
                for(int k = 0; k < 4; k++) {
                    int tmpRow = r + diagRow[k];
                    int tmpCol = c + diagCol[k];

                    if(tmpRow < 0 || tmpRow >= n || tmpCol < 0 || tmpCol >= n)
                        continue;

                    if(board[tmpRow][tmpCol] > 0) {
                        diagWaterAmt++;
                    }
                }

                board[r][c] += diagWaterAmt;
            }
        }
    }

    // 5. 바구니에 저장된 물의 양이 2 이상인 모든 칸에 구름이 생기고,
    // 물의 양이 2 줄어든다.

    for(int r = 0; r < n; r++) {
        for(int c = 0; c < n; c++) {
            if(newCloud[r][c] == CLOUD) continue; // 구름이 사라진 칸

            if(board[r][c] >= 2) {
                board[r][c] -= 2;
                cloud[r][c] = CLOUD;
            }
        }
    }
}

int getTotal() {
    int res = 0;

    for(int r = 0; r < n; r++) {
        for(int c = 0; c < n; c++) {
            res += board[r][c];
        }
    }

    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    board.resize(n, vector<int>(n));
    cloud.resize(n, vector<int>(n, 0));

    // 비바라기
    cloud[n - 1][0] = 1;
    cloud[n - 1][1] = 1;
    cloud[n - 2][0] = 1;
    cloud[n - 2][1] = 1;

    // 물의 양 저장
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < m; i++) {
        int d, s;
        cin >> d >> s;

        move(d - 1, s);
    }

    cout << getTotal() << "\n";

    return 0;
}