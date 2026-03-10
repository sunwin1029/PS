#include <bits/stdc++.h>
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3
#define EMPTY 0
#define WALL 1
#define CLEAN 2
using namespace std;

int n, m;
int r, c, d;
int cleanAmt = 0;

int drow[4] = {-1, 0, 1, 0}; // 북, 동, 남, 서
int dcol[4] = {0, 1, 0, -1};
vector <vector <int>> board;

void clean() {
    bool canNext = true;

    while(canNext) {
        // 청소되지 않은 경우, 청소
        if(board[r][c] == EMPTY) {
            cleanAmt++;
            board[r][c] = CLEAN;
        }

        // 현재 주변 4칸 중 청소되지 않은 빈 칸을 찾음
        bool cleanPossible = false;

        for(int i = 1; i <= 4; i++) {
            int tmpD = (d + 4 - i) % 4; // 반시계 회전

            int newRow = r + drow[tmpD];
            int newCol = c + dcol[tmpD];

            // 청소되지 않은 빈칸 찾으면 해당 방향으로 전진
            if(board[newRow][newCol] == EMPTY) {
                cleanPossible = true;
                r = newRow;
                c = newCol;
                d = tmpD;
                break;
            }
        }
        // 주위 4칸에 빈칸 없음
        if(!cleanPossible) {
            int newRow = r + drow[(d + 2) % 4];
            int newCol = c + dcol[(d + 2) % 4];

            // 후진 불가능
            if(board[newRow][newCol] == WALL) {
                canNext = false;
            }
            else {
                r = newRow;
                c = newCol;
            }
        }
    }    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> r >> c >> d;

    board.resize(n, vector<int>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    clean();

    cout << cleanAmt << "\n";

    return 0;
}