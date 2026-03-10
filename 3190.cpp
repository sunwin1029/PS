#include <bits/stdc++.h>
#define EMPTY 0
#define SNAKE 1
#define APPLE 2
#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3
using namespace std;

int drow[4] = {-1, 0, 1, 0}; // 상좌하우
int dcol[4] = {0, -1, 0, 1};
int direction = RIGHT; // 뱀의 이동방향

void rotate(char cmd) {
    if(cmd == 'L') {
        direction = (direction + 1) % 4;
    }
    else if(cmd == 'D') {
        direction = (direction + 7) % 4; 
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; // 판 크기
    int k; // 사과 수
    int l; // 회전 수

    cin >> n;
    cin >> k;

    vector <vector <int>> board(n + 2, vector <int> (n + 2, EMPTY));

    // 가장자리 벽 만들기
    for(int i = 0; i <= n + 1; i++) {
        board[0][i] = SNAKE;
        board[i][0] = SNAKE;
        board[n + 1][i] = SNAKE;
        board[i][n + 1] = SNAKE;
    }

    for(int i = 0; i < k; i++) {
        int row, col;

        cin >> row >> col;

        board[row][col] = APPLE;
    }

    cin >> l;

    vector <pair <int, char>> movement(l); // 이동횟수 저장

    for(int i = 0; i < l; i++) {
        cin >> movement[i].first >> movement[i].second;
    }
    movement.push_back({INT_MAX, 0}); // 회전이 끝난 이후의 움직임 지정

    bool gameOver = false;
    deque <pair <int, int>> snakeState; // 뱀의 위치를 저장

    snakeState.push_front({1, 1});
    board[1][1] = SNAKE;
    int time = 0;

    for(int i = 0; i < l + 1; i++) {
        while(time < movement[i].first) {
            time++;
            pair <int, int> head = snakeState.front();
            pair <int, int> tail = snakeState.back();

            int nextRow = head.first + drow[direction];
            int nextCol = head.second + dcol[direction];

            // 벽, 뱀에 부딪힘
            if(board[nextRow][nextCol] == SNAKE) {
                gameOver = true;
                break;
            }
            // 벽, 뱀에 부딪히지 않은 경우
            else {
                // 사과를 못먹은 경우는, 꼬리 부분 빈공간으로 바꿔줘야 함
                if(board[nextRow][nextCol] != APPLE) {
                    board[tail.first][tail.second] = EMPTY;
                    snakeState.pop_back();
                }

                snakeState.push_front({nextRow, nextCol}); // 새로운 머리 위치 추가
                board[nextRow][nextCol] = SNAKE; // 판에서의 상태 변경
            }
        }
        if(gameOver) break;
        rotate(movement[i].second);
        
    }

    cout << time << "\n";

    return 0;
}