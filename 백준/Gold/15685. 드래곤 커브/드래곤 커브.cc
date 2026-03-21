#include <bits/stdc++.h>
#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3
using namespace std;

vector <int> dragon;
vector <vector <bool>> board(101, vector <bool>(101));
vector <vector <bool>> boardRow(101, vector <bool>(101));
vector <vector <bool>> boardCol(101, vector <bool>(101));

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 드래곤 커브 만들기
    dragon.push_back(RIGHT);
    for(int i = 1; i <= 10; i++) {
        int size = dragon.size();

        for(int j = size - 1; j >= 0; j--) {
            dragon.push_back((dragon[j] + 3) % 4);
        }
    }

    int n;

    cin >> n;

    // 드래곤 커브 그리기
    for(int i = 0; i < n; i++) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        switch(d) {
            case 0:
                d = RIGHT;
                break;
            case 1:
                d = UP;
                break;
            case 2:
                d = LEFT;
                break;
            case 3:
                d = DOWN;
                break;
        }

        board[x][y] = true;

        for(int j = 0; j < (1 << g); j++) {
            int tmpDir = (dragon[j] + d) % 4;

            switch(tmpDir) {
                case RIGHT:
                    board[x + 1][y] = true;
                    x++;
                    break;
                case LEFT:
                    board[x - 1][y] = true;
                    x--;
                    break;
                case UP:
                    board[x][y - 1] = true;
                    y--;
                    break;
                case DOWN:
                    board[x][y + 1] = true;
                    y++;
                    break;
            }
        }
    }

    // 정사각형 세기
    int res = 0;
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            if(board[i][j] == true && board[i + 1][j] == true && board[i][j + 1] == true && board[i + 1][j + 1] == true) {
                res++;
            }
        }
    }

    cout << res << "\n";


    return 0;
}