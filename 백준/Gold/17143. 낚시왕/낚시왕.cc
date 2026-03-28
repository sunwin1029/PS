#include <bits/stdc++.h>
using namespace std;

int r, c, m;
int fishKing = 0;
int drow[5] = {0, -1, 1, 0, 0};  // 위, 아래, 오른쪽, 왼쪽
int dcol[5] = {0, 0, 0, 1, -1};

class Shark {
   public:
    int d;
    int s;
    int z;
    bool isMove;

    Shark() : d(0), s(0), z(0), isMove(false) {}

    Shark(int d, int s, int z) : d(d), s(s), z(z), isMove(false) {}
};

vector<vector<Shark>> board;

int reverse(int d) {
    switch(d) {
        case 1:
            return 2;
            break;
        case 2:
            return 1;
            break;
        case 3:
            return 4;
            break;
        case 4:
            return 3;
            break;
    }

    return 0;
}

// 0 1 2 3

void move(int r1, int c1) {
    Shark shark = board[r1][c1];
    board[r1][c1] = Shark();

    int newRow = r1;
    int newCol = c1;
    shark.isMove = true;
    // 상하이동
    if(shark.d < 3) {
        int moveCount = shark.s % (2 * (r - 1));

        for(int i = 0; i < moveCount; i++) {
            if(newRow + drow[shark.d] < 0 || newRow + drow[shark.d] >= r) {
                shark.d = reverse(shark.d);
            }

            newRow = newRow + drow[shark.d];
        }
    }

    // 좌우이동
    else {
        int moveCount = shark.s % (2 * (c - 1));

        for(int i = 0; i < moveCount; i++) {
            if(newCol + dcol[shark.d] < 0 || newCol + dcol[shark.d] >= c) {
                shark.d = reverse(shark.d);
            }

            newCol = newCol + dcol[shark.d];
        }
    }

    // 이동 위치에 아무것도 없는 경우
    if(board[newRow][newCol].z == 0) {
        board[newRow][newCol] = shark;
    } else {
        // 해당 위치에 움직여야 할 상어가 있는 경우
        if(!board[newRow][newCol].isMove) {
            move(newRow, newCol);
        }

        if(board[newRow][newCol].z == 0) {
            board[newRow][newCol] = shark;
        } else {
            Shark shark2 = board[newRow][newCol];

            board[newRow][newCol] = (shark.z > shark2.z ? shark : shark2);
        }
    }
}

void moveProcess() {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(board[i][j].s > 0 && !board[i][j].isMove) move(i, j);
        }
    }
}

void moveInitialIze() {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            board[i][j].isMove = false;
        }
    }
}

void fishing() {
    int res = 0;

    for(int i = 0; i < c; i++) {
        for(int j = 0; j < r; j++) {
            if(board[j][i].z == 0) continue;
            // 상어를 잡음
            else {
                res += board[j][i].z;
                board[j][i] = Shark();
                break;
            }
        }
        moveProcess();
        moveInitialIze();
    }

    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c >> m;
    board.resize(r, vector<Shark>(c, Shark()));

    for(int i = 0; i < m; i++) {
        int a, b, c, d, e;

        cin >> a >> b >> c >> d >> e;

        board[a - 1][b - 1] = Shark(d, c, e);
    }

    fishing();

    return 0;
}
