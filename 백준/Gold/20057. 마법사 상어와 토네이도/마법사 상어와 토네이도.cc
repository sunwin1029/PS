#include <bits/stdc++.h>
#define LEFT 0
#define DOWN 1
#define RIGHT 2
#define UP 3
#define CUR board[des.first][des.second]
using namespace std;

vector<vector<int>> board;
int n;
int res = 0;

int move(int amt, int desRow, int desCol);
void tornado(int dir, pair<int, int> des);

void tornadoMove() {
    int r = n / 2;
    int c = n / 2;

    int len = 1;
    int dir = LEFT;

    while(true) {
        for(int repeat = 0; repeat < 2; repeat++) {
            for(int i = 0; i < len; i++) {
                if(dir == LEFT)
                    c--;
                else if(dir == DOWN)
                    r++;
                else if(dir == RIGHT)
                    c++;
                else if(dir == UP)
                    r--;

                tornado(dir, {r, c});

                if(r == 0 && c == 0) return;
            }

            dir = (dir + 1) % 4;
        }
        len++;
    }
}

void tornado(int dir, pair<int, int> des) {
    int r = des.first;
    int c = des.second;

    int lastAmt = board[r][c];

    int sand7 = lastAmt * 7 / 100;
    int sand10 = lastAmt / 10;
    int sand2 = lastAmt / 50;
    int sand1 = lastAmt / 100;
    int sand5 = lastAmt / 20;

    if(dir == LEFT) {
        CUR -= move(sand7, r - 1, c);
        CUR -= move(sand7, r + 1, c);
        CUR -= move(sand2, r - 2, c);
        CUR -= move(sand2, r + 2, c);
        CUR -= move(sand10, r - 1, c - 1);
        CUR -= move(sand10, r + 1, c - 1);
        CUR -= move(sand5, r, c - 2);
        CUR -= move(sand1, r - 1, c + 1);
        CUR -= move(sand1, r + 1, c + 1);

        if(c - 1 >= 0)
            board[r][c - 1] += CUR;
        else
            res += CUR;
        CUR = 0;
    }
    if(dir == UP) {
        CUR -= move(sand7, r, c - 1);
        CUR -= move(sand7, r, c + 1);
        CUR -= move(sand2, r, c - 2);
        CUR -= move(sand2, r, c + 2);
        CUR -= move(sand10, r - 1, c - 1);
        CUR -= move(sand10, r - 1, c + 1);
        CUR -= move(sand5, r - 2, c);
        CUR -= move(sand1, r + 1, c - 1);
        CUR -= move(sand1, r + 1, c + 1);

        if(r - 1 >= 0)
            board[r - 1][c] += CUR;
        else
            res += CUR;
        CUR = 0;
    }
    if(dir == RIGHT) {
        CUR -= move(sand7, r - 1, c);
        CUR -= move(sand7, r + 1, c);
        CUR -= move(sand2, r - 2, c);
        CUR -= move(sand2, r + 2, c);
        CUR -= move(sand1, r - 1, c - 1);
        CUR -= move(sand1, r + 1, c - 1);
        CUR -= move(sand5, r, c + 2);
        CUR -= move(sand10, r - 1, c + 1);
        CUR -= move(sand10, r + 1, c + 1);

        if(c + 1 < n)
            board[r][c + 1] += CUR;
        else
            res += CUR;
        CUR = 0;
    }
    if(dir == DOWN) {
        CUR -= move(sand7, r, c - 1);
        CUR -= move(sand7, r, c + 1);
        CUR -= move(sand2, r, c - 2);
        CUR -= move(sand2, r, c + 2);
        CUR -= move(sand10, r + 1, c - 1);
        CUR -= move(sand10, r + 1, c + 1);
        CUR -= move(sand5, r + 2, c);
        CUR -= move(sand1, r - 1, c - 1);
        CUR -= move(sand1, r - 1, c + 1);

        if(r + 1 < n)
            board[r + 1][c] += CUR;
        else
            res += CUR;
        CUR = 0;
    }
}

int move(int amt, int desRow, int desCol) {
    if(desRow < 0 || desRow >= n || desCol < 0 || desCol >= n) {
        res += amt;
        return amt;
    } else {
        board[desRow][desCol] += amt;
    }
    return amt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    board.resize(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    tornadoMove();

    cout << res << "\n";

    return 0;
}