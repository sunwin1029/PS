#include <bits/stdc++.h>
#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4
#define WHITE 0
#define RED 1
#define BLUE 2
using namespace std;

int drow[5] = {0, 0, 0, -1, 1};
int dcol[5] = {0, 1, -1, 0, 0};

int n, k;
vector<vector<vector<int>>> boardPiece;  // 판에 있는 말들을 보여줌
vector<vector<int>> board;               // 판의 상태
vector<tuple<int, int, int>> piece;      // {row, col, dir}

int reverseDir(int dir) {
    switch(dir) {
        case 1:
            return 2;
        case 2:
            return 1;
        case 3:
            return 4;
        case 4:
            return 3;
    }
    return 0;
}

bool process() {
    for(int i = 0; i < k; i++) {
        int row = get<0>(piece[i]);
        int col = get<1>(piece[i]);
        int dir = get<2>(piece[i]);

        // 현재 위치에 있는 말들
        vector<int> tmp = boardPiece[row][col];
        // 뒤집을 컨테이너
        vector<int> container;
        // 현재 말이 위치한 인덱스
        int index = 0;

        // 현재 말이 위치한 index 확인하기
        while(true) {
            if(tmp[index] == i) break;
            index++;
        }

        // 이동위치
        int newRow = row + drow[dir];
        int newCol = col + dcol[dir];

        // 파란색에 도착한 경우 또는 밖으로 나가려는 경우
        if(newRow < 0 || newRow >= n || newCol < 0 || newCol >= n ||
           board[newRow][newCol] == BLUE) {
            newRow = row + drow[reverseDir(dir)];
            newCol = col + dcol[reverseDir(dir)];

            // 방향 반전 시켜주기
            get<2>(piece[i]) = reverseDir(get<2>(piece[i]));

            // 방향을 바꾼 뒤 이동하려 해도 파란색인 경우 또는 밖으로 나가려는 경우
            if(newRow < 0 || newRow >= n || newCol < 0 || newCol >= n ||
               board[newRow][newCol] == BLUE) {
                // 가만히 있기
                continue;
            }
        }

        // 이동할 말 전체 컨테이너에 넣기
        int tmpIndex = index;
        for(; tmpIndex < tmp.size(); tmpIndex++) {
            container.push_back(tmp[tmpIndex]);
        }

        // 이동할 칸이 빨간색인 경우 뒤집기
        if(board[newRow][newCol] == RED) {
            reverse(container.begin(), container.end());
        }

        // piece의 상태 바꿔주기
        for(int j = 0; j < container.size(); j++) {
            // piece의 위치 바꾸기
            int pieceNum = container[j];

            // 행과 열 위치 바꿔주기
            get<0>(piece[pieceNum]) = newRow;
            get<1>(piece[pieceNum]) = newCol;
        }

        // 판에 있는 piece 옮기기

        // 기존 위치에서 piece들 제거
        for(; index < tmp.size(); index++) {
            boardPiece[row][col].pop_back();
        }

        // 말 이동시키기
        for(int j = 0; j < container.size(); j++) {
            boardPiece[newRow][newCol].push_back(container[j]);
        }
        
        if(boardPiece[newRow][newCol].size() >= 4) {
            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    boardPiece.resize(n, vector<vector<int>>(n));
    board.resize(n, vector<int>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < k; i++) {
        tuple<int, int, int> tmp;
        cin >> get<0>(tmp) >> get<1>(tmp) >> get<2>(tmp);

        get<0>(tmp)--;
        get<1>(tmp)--;

        // 말에 대한 기록
        piece.push_back(tmp);
        // 판에 어떤 말들이 어디 위치하는지 기록
        boardPiece[get<0>(tmp)][get<1>(tmp)].push_back(i);
    }

    int res = 1;

    while(!process() && res < 1001) {
        res++;
    }

    cout << (res > 1000 ? -1 : res) << "\n";

    return 0;
}