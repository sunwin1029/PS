#include <bits/stdc++.h>
using namespace std;

int n, m;
int ladder[110];
int snake[110];
int board[110];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i = 2; i < 110; i++) {
        board[i] = 1e9;
    }

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        cin >> ladder[tmp];
    }
    for(int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        cin >> snake[tmp];
    }

    for(int i = 1; i <= 100; i++) {
        for(int j = 1; j <= 6; j++) {
            if(i - j < 0) continue; // 0보다 이전칸
            board[i] = min(board[i], board[i - j] + 1);
        }

        // 해당 칸이 사다리로 연결된 경우
        if(ladder[i]) {
            board[ladder[i]] = min(board[ladder[i]], board[i]);
            board[i] = 1e9; // 해당 칸은 도달 불가능
        }
        if(snake[i]) {
            if(board[snake[i]] > board[i]) {
                board[snake[i]] = board[i];
                board[i] = 1e9; // 해당 칸은 도달 불가능
                i = snake[i]; // snake를 타고 가는 최소값 검사하기
            }
            else {
                board[i] = 1e9; // 해당 칸은 불가능
            }
        }
    }

    cout << board[100] << "\n";



    return 0;
}