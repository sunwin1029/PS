#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int row, col;

int dice[6] = {0};
int drow[4] = {0, 0, -1, 1};  // 동서북남 
int dcol[4] = {1, -1, 0, 0};
vector <vector <int>> board;

//      1
//  3   0   2
//      4
//      5

void rollWest() {
    int tmp = dice[0];
    dice[0] = dice[3];
    dice[3] = dice[5];
    dice[5] = dice[2];
    dice[2] = tmp;
}

void rollEast() {
    int tmp = dice[0];
    dice[0] = dice[2];
    dice[2] = dice[5];
    dice[5] = dice[3];
    dice[3] = tmp;
}

void rollNorth() {
    int tmp = dice[0];
    dice[0] = dice[1];
    dice[1] = dice[5];
    dice[5] = dice[4];
    dice[4] = tmp;
}

void rollSouth() {
    int tmp = dice[0];
    dice[0] = dice[4];
    dice[4] = dice[5];
    dice[5] = dice[1];
    dice[1] = tmp;
}


void roll(int cmd) {
    int newRow = row + drow[cmd - 1];
    int newCol = col + dcol[cmd - 1];

    if(newRow < 0 || newRow >= n || newCol < 0 || newCol >= m) return;

    switch(cmd) {
        case 1:
            rollEast();
            break;
        case 2:
            rollWest();
            break;
        case 3:
            rollNorth();
            break;
        case 4:
            rollSouth();
            break;
    }

    if(board[newRow][newCol] == 0) {
        board[newRow][newCol] = dice[0];
    }
    else {
        dice[0] = board[newRow][newCol];
        board[newRow][newCol] = 0;
    }

    cout << dice[5] << "\n";

    row = newRow;
    col = newCol;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> row >> col >> k;
    board.resize(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < k; i++) {
        int cmd;
        cin >> cmd;
        roll(cmd);
    }

    return 0;
}