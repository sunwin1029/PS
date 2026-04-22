#include <bits/stdc++.h>
using namespace std;

int n;
int res = INT_MAX;
int board[20][20];

int findT() {
    int res = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(board[i][j] == 'T') res++;
        }
    }

    return res;
}

void rotateRow(int rowNum) {
    for(int i = 0; i < n; i++) {
        board[rowNum][i] = (board[rowNum][i] == 'T' ? 'H' : 'T');
    }
}

void rotateCol(int colNum) {
    for(int i = 0; i < n; i++) {
        board[i][colNum] = (board[i][colNum] == 'T' ? 'H' : 'T');
    }
}

void program(int rowNum) {
    // 행에 대한 회전 끝남
    if(rowNum == n) {
        int numT = 0;
        int mask = 0;
        for(int i = 0; i < n; i++) {
            int numT = 0;
            for(int j = 0; j < n; j++) {
                if(board[j][i] == 'T') numT++;
            }

            if(numT > n / 2) {
                rotateCol(i);
                mask |= (1 << i);
            }
        }

        res = min(res, findT());

        for(int i = 0; i < n; i++) {
            if(mask & (1 << i) != 0) {
                rotateCol(i);
            }
        }

        return;
    }

    rotateRow(rowNum);
    program(rowNum + 1);
    rotateRow(rowNum);
    program(rowNum + 1);
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for(int j = 0; j < n; j++) {
            board[i][j] = s[j];
        }
    }

    program(0);

    cout << res << "\n";

    return 0;
}