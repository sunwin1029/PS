#include <bits/stdc++.h>
using namespace std;

int n, m, h;
int res = INT_MAX;
vector<vector<int>> ladderBoard;

bool searchCol(int col) {
    int tmp = col;

    for(int row = 1; row <= h; row++) {
        if(ladderBoard[row][col - 1] != 0) {
            col--;
        } else if(ladderBoard[row][col] != 0) {
            col++;
        }
    }

    return tmp == col;
}

bool searchAll() {
    bool possible = true;

    for(int i = 1; i <= n; i++) {
        if(!searchCol(i)) {
            possible = false;
            break;
        }
    }

    return possible;
}

void backTracking(int row, int col, int additionalLadder) {
    // 추가 사다리가 3개 이상 된 경우
    if(additionalLadder >= 3 || additionalLadder >= res) return;

    // index를 벗어난 경우
    if(col > n - 1) {
        backTracking(row + 1, 1, additionalLadder);
        return;
    }
    if(row > h) {
        return;
    }

    // 사다리를 설치할 수 없는 경우(이전 인덱스에 있는 경우, 현재 인덱스에 있는
    // 경우, 다음 인덱스에 있는 경우)
    if(ladderBoard[row][col] != 0 || ladderBoard[row][col - 1] != 0 ||
       ladderBoard[row][col + 1] != 0) {
        backTracking(row, col + 1, additionalLadder);
        return;
    } else {
        // 해당 부분에 사다리 부여
        ladderBoard[row][col] = 1;
        // 문제의 조건이 가능한경우
        if(searchAll()) {
            res = min(res, additionalLadder + 1);

        } else {
            backTracking(row, col + 2, additionalLadder + 1);
        }

        ladderBoard[row][col] = 0;
    }

    backTracking(row, col + 1, additionalLadder);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> h;
    ladderBoard.resize(h + 1, vector<int>(n + 2));

    for(int i = 0; i < m; i++) {
        int row, col;
        cin >> row >> col;
        ladderBoard[row][col] = 1;
    }

    if(searchAll()) {
        cout << 0 << "\n";
        return 0;
    }

    backTracking(1, 1, 0);

    cout << ((res == INT_MAX) ? -1 : res) << "\n";

    return 0;
}