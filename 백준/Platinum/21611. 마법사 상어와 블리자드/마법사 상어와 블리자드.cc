#include <bits/stdc++.h>
#define EMPTY 0
using namespace std;

int n, m;
vector<vector<int>> board;
int drow[5] = {0, -1, 1, 0, 0};  // 상, 하, 좌, 우
int dcol[5] = {0, 0, 0, -1, 1};

int dr[4] = {0, 1, 0, -1};  // 좌, 하, 우, 상
int dc[4] = {-1, 0, 1, 0};

int explode[4] = {
    0,
};  // 폭발 구슬 수 저장

void process();
void blizard(int d, int s);
void beadMove();
void beadChange();
bool explosion();

void process() {
    int d, s;
    cin >> d >> s;

    blizard(d, s);
    beadMove();

    while(explosion()) {
        beadMove();
    }

    beadChange();
}

void blizard(int d, int s) {
    int sharkR = n / 2;
    int sharkC = n / 2;

    for(int i = 1; i <= s; i++) {
        int newR = sharkR + drow[d] * i;
        int newC = sharkC + dcol[d] * i;

        if(newR < 0 || newR >= n || newC < 0 || newC >= n) continue;

        board[newR][newC] = 0;
    }
}

void beadMove() {
    int len = 1;
    int dir = 0;
    queue<pair<int, int>> emptySlot;

    // 초기 위치
    int r = n / 2;
    int c = n / 2;

    while(true) {
        for(int repeat = 0; repeat < 2; repeat++) {
            for(int i = 0; i < len; i++) {
                r += dr[dir];
                c += dc[dir];
                if(r < 0 || r >= n || c < 0 || c >= n) return;

                // 빈공간이면 슬롯에 넣기
                if(board[r][c] == EMPTY) {
                    emptySlot.push({r, c});
                } else {
                    // 채워넣을 공간이 있으면
                    if(!emptySlot.empty()) {
                        int newR = emptySlot.front().first;
                        int newC = emptySlot.front().second;

                        emptySlot.pop();

                        // 채워넣기
                        board[newR][newC] = board[r][c];
                        board[r][c] = EMPTY;

                        // 있던 공간은 빈공간 슬롯에 집어넣기
                        emptySlot.push({r, c});
                    }
                }
            }
            dir = (dir + 1) % 4;
        }
        len++;
    }
}

bool explosion() {
    bool isExplode = false;
    int len = 1;
    int dir = 0;

    // 초기 위치
    int r = n / 2;
    int c = n / 2;

    int repeatNum = 0;
    int beadType = -1;

    queue<pair<int, int>> sameTypeStore;  // 같은 타입의 구슬 저장

    while(true) {
        for(int repeat = 0; repeat < 2; repeat++) {
            for(int i = 0; i < len; i++) {
                r += dr[dir];
                c += dc[dir];
                if(r < 0 || r >= n || c < 0 || c >= n || board[r][c] == EMPTY) {
                    if(repeatNum >= 4) {
                        while(!sameTypeStore.empty()) {
                            pair<int, int> tmp = sameTypeStore.front();
                            sameTypeStore.pop();
                            explode[beadType]++;
                            board[tmp.first][tmp.second] = EMPTY;
                            isExplode = true;
                        }
                    }

                    return isExplode;
                }

                // 타입이 같은 경우
                if(beadType == board[r][c]) {
                    repeatNum++;
                    sameTypeStore.push({r, c});
                }
                // 구슬 타입이 같지 않은 경우
                else {
                    // 4개 이상 연속한 경우 폭발
                    if(repeatNum >= 4) {
                        while(!sameTypeStore.empty()) {
                            pair<int, int> tmp = sameTypeStore.front();
                            sameTypeStore.pop();
                            explode[beadType]++;
                            board[tmp.first][tmp.second] = EMPTY;

                            isExplode = true;
                        }
                    } else {
                        // 리스트에서 제거
                        while(!sameTypeStore.empty()) {
                            sameTypeStore.pop();
                        }
                        
                    }

                    // 새로운 구슬 타입, 수 지정
                    beadType = board[r][c];
                    sameTypeStore.push({r, c});

                    repeatNum = 1;
                }
            }
            dir = (dir + 1) % 4;
        }
        len++;
    }

    return isExplode;
}

void beadChange() {
    int len = 1;
    int dir = 0;

    // 초기 위치
    int r = n / 2;
    int c = n / 2;

    int beadType = board[r][c - 1];
    int repeatNum = 0;

    queue<pair<int, int>> group;

    bool isBreak = false;

    while(true) {
        if(isBreak) break;
        for(int repeat = 0; repeat < 2; repeat++) {
            if(isBreak) break;

            for(int i = 0; i < len; i++) {
                r += dr[dir];
                c += dc[dir];
                if(r < 0 || r >= n || c < 0 || c >= n || board[r][c] == EMPTY) {
                    group.push({repeatNum, beadType});
                    isBreak = true;
                    break;
                }

                if(board[r][c] == beadType) {
                    repeatNum++;
                } else {
                    group.push({repeatNum, beadType});
                    beadType = board[r][c];
                    repeatNum = 1;
                }
            }
            dir = (dir + 1) % 4;
        }
        len++;
    }

    // 재 초기화

    r = n / 2;
    c = n / 2;
    len = 1;
    dir = 0;
    int groupNum = -1;
    bool isFinish = false;

    while(true) {
        for(int repeat = 0; repeat < 2; repeat++) {
            for(int i = 0; i < len; i++) {
                r += dr[dir];
                c += dc[dir];


                if(r < 0 || r >= n || c < 0 || c >= n) return;

                if(isFinish) {
                    board[r][c] = EMPTY;
                    continue;
                }

                // 새로 뽑아넣어야 하는 경우
                if(groupNum < 0) {
                    if(group.empty()) {
                        board[r][c] = EMPTY;
                        isFinish = true;
                    }

                    else {
                        pair<int, int> tmp = group.front();
                        group.pop();

                        board[r][c] = tmp.first;
                        groupNum = tmp.second;
                    }
                    
                }
                // groupNum 넣어야 하는 경우
                else {
                    board[r][c] = groupNum;
                    groupNum = -1;
                }
            }
            dir = (dir + 1) % 4;
        }
        len++;
    }
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

    while(m--) {
        process();
    }

    cout << explode[1] + explode[2] * 2 + explode[3] * 3 << "\n";

    return 0;
}