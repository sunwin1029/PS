#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int>> board;




// 물고기 수가 가장 적은 어항에 물고기 넣기
void addFish() {
    int minAmt = INT_MAX;

    for(int i = 0; i < n; i++) {
        minAmt = min(minAmt, board[0][i]);
    }

    for(int i = 0; i < n; i++) {
        if(board[0][i] == minAmt) board[0][i]++;
    }
}

// 좌측 정렬
void leftAlign() {
    for(int r = 0; r < n; r++) {
        int idx = 0;
        for(int c = 0; c < n; c++) {
            if(board[r][c] != 0) {
                board[r][idx++] = board[r][c];
            }
        }

        while(idx < n) {
            board[r][idx++] = 0;
        }
    }
}

// 물고기 쌓기
void stackUp() {
    int moveBoxWidth = 1;
    int moveBoxHeight = 2;
    int curX = 1;
    int curY = 0;

    // 최초 1회 회전
    board[1][1] = board[0][0];
    board[0][0] = 0;

    int remainWidth = n - (curX + moveBoxWidth);

    while(moveBoxHeight <= remainWidth) {
        vector<vector<int>> tmp(moveBoxWidth, vector<int>(moveBoxHeight));

        // 회전 배열에 넣어놓기
        for(int r = 0; r < moveBoxHeight; r++) {
            for(int c = 0; c < moveBoxWidth; c++) {
                tmp[moveBoxWidth - 1 - c][r] = board[curY + r][curX + c];
                board[curY + r][curX + c] = 0;
            }
        }

        // 회전시켜서 배치
        int nextX = curX + moveBoxWidth;
        for(int r = 0; r < moveBoxWidth; r++) {
            for(int c = 0; c < moveBoxHeight; c++) {
                board[curY + 1 + r][nextX + c] = tmp[r][c];
            }
        }

        // 다음 박스 크기 계산
        int nextWidth = moveBoxHeight;
        int nextHeight = moveBoxWidth + 1;

        curX = nextX;
        moveBoxWidth = nextWidth;
        moveBoxHeight = nextHeight;
        remainWidth = n - (curX + moveBoxWidth);
    }
}

void stackUp2() {
    int half = n / 2;
    int quarter = n / 4;

    // 왼쪽 절반을 뒤집어 오른쪽 절반 위에 올린다.
    for(int c = 0; c < half; c++) {
        board[1][n - 1 - c] = board[0][c];
        board[0][c] = 0;
    }

    // 다시 왼쪽 절반(2 x N/4)을 180도 회전해 오른쪽 위에 올린다.
    vector<vector<int>> tmp(2, vector<int>(quarter));
    for(int r = 0; r < 2; r++) {
        for(int c = 0; c < quarter; c++) {
            tmp[1 - r][quarter - 1 - c] = board[r][half + c];
            board[r][half + c] = 0;
        }
    }

    int startCol = half + quarter;
    for(int r = 0; r < 2; r++) {
        for(int c = 0; c < quarter; c++) {
            board[r + 2][startCol + c] = tmp[r][c];
        }
    }
}

void diffusion() {
    vector <vector <int>> storeDif;

    storeDif.resize(n, vector<int>(n, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - 1; j++) {
            if(board[i][j] == 0 || board[i][j + 1] == 0) continue;

            int dif = board[i][j] - board[i][j + 1];
            dif /= 5;

            storeDif[i][j] -= dif;
            storeDif[i][j + 1] += dif;
        }
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 0 || board[i + 1][j] == 0) continue;

            int dif = board[i][j] - board[i + 1][j];
            dif /= 5;

            storeDif[i][j] -= dif;
            storeDif[i + 1][j] += dif;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            board[i][j] += storeDif[i][j];
        }
    }
}


void stackDown() {
    vector <int> tmp;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[j][i] > 0) {
                tmp.push_back(board[j][i]);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        board[0][i] = tmp[i];
    }

    for(int r = 1; r < n; r++) {
        for(int c = 0; c < n; c++) {
            board[r][c] = 0;
        }
    }
}

int getDif() {
    int fishMax = 0;
    int fishMin = INT_MAX;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 0) continue;

            fishMax = max(fishMax, board[i][j]);
            fishMin = min(fishMin, board[i][j]);
        }
    }

    return fishMax - fishMin;
}


bool program() {
    if(getDif() <= k) return true;

    addFish();
    stackUp();
    diffusion();
    stackDown();
    stackUp2();
    diffusion();
    stackDown();

    return false;    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int res = 0;

    cin >> n >> k;
    board.resize(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        cin >> board[0][i];
    }

    while(!program()) {
        res++;
    }

    cout << res << "\n";


    return 0;
}
