#include <bits/stdc++.h>
#define BLOCK 1
#define EMPTY 0
using namespace std;

vector <vector <int>> redBoard(4, vector<int>(4, EMPTY));
vector <vector <int>> blueBoard(4, vector<int>(6, EMPTY));
vector <vector<int>> greenBoard(6, vector<int>(4));
int score = 0;


void process();
void putBlue(int t, int row, int col);
void clearBlue();
void putGreen(int t, int row, int col);
void clearGreen();

void process() {
    int t, x, y;
    cin >> t >> x >> y;

    putBlue(t, x, y);
    clearBlue();
    putGreen(t, x, y);
    clearGreen();
}

void putBlue(int t, int row, int col) {
    // 블록 놓기
    if(t != 3) {
        int i;
        for(i = 0; i < 6; i++) {
            if(blueBoard[row][i] == BLOCK) {
                i--; // 블럭이 놓여야 할 위치
                break;
            }
        }

        if(i == 6) {
            i = 5;
        }

        blueBoard[row][i] = BLOCK;

        if(t == 2)
            blueBoard[row][i - 1] = BLOCK;

    }
    if(t == 3) {
        int i;
        for(i = 0; i < 6; i++) {
            if(blueBoard[row][i] == BLOCK || blueBoard[row + 1][i] == BLOCK) {
                i--;  // 블럭이 놓여야 할 위치
                break;
            }
        }

        if(i == 6) {
            i = 5;
        }

        blueBoard[row][i] = BLOCK;
        blueBoard[row + 1][i] = BLOCK;
    }
}

void clearBlue() {
    for(int i = 5; i >= 2; i--) {
        int shouldClear = true;

        // 줄이 다 찼는지 확인
        for(int j = 0; j < 4; j++) {
            if(blueBoard[j][i] != BLOCK) {
                shouldClear = false;
            }
        }

        // 한줄이 다 채워진 경우
        if(shouldClear) {
            for(int j = i - 1; j >= 0; j--) {
                for(int row = 0; row < 4; row++) {
                    blueBoard[row][j + 1] = blueBoard[row][j];
                }
            }
            score++;
            i++;

            for(int row = 0; row < 4; row++) {
                blueBoard[row][0] = EMPTY;
            }
        }
    }

    // 몇줄 땡겨야 하는지 확인
    int specialLine = 0;
    for(int i = 0; i < 2; i++) {
        bool isSpecial = false;
        for(int j = 0; j < 4; j++) {
            if(blueBoard[j][i] == BLOCK) {
                isSpecial = true;
                break;
            }
        }

        if(isSpecial) specialLine++;
    }

    if(specialLine == 1) {
        for(int j = 4; j >= 0; j--) {
            for(int row = 0; row < 4; row++) {
                blueBoard[row][j + 1] = blueBoard[row][j];
            }
        }
        for(int row = 0; row < 4; row++) {
            blueBoard[row][0] = EMPTY;
        }
    }
    if(specialLine == 2) {
        for(int j = 3; j >= 0; j--) {
            for(int row = 0; row < 4; row++) {
                blueBoard[row][j + 2] = blueBoard[row][j];
            }
        }

        for(int row = 0; row < 4; row++) {
            blueBoard[row][0] = EMPTY;
            blueBoard[row][1] = EMPTY;
        }
    }


}

void clearGreen() {
    for(int i = 5; i >= 2; i--) {
        int shouldClear = true;

        // 줄이 다 찼는지 확인
        for(int j = 0; j < 4; j++) {
            if(greenBoard[i][j] != BLOCK) {
                shouldClear = false;
            }
        }

        // 한줄이 다 채워진 경우
        if(shouldClear) {
            for(int j = i - 1; j >= 0; j--) {
                for(int col = 0; col < 4; col++) {
                    greenBoard[j + 1][col] = greenBoard[j][col];
                }
            }
            score++;
            i++;

            for(int col = 0; col < 4; col++) {
                greenBoard[0][col] = EMPTY;
            }
        }
    }

    // 몇줄 땡겨야 하는지 확인
    int specialLine = 0;
    for(int i = 0; i < 2; i++) {
        bool isSpecial = false;
        for(int j = 0; j < 4; j++) {
            if(greenBoard[i][j] == BLOCK) {
                isSpecial = true;
                break;
            }
        }

        if(isSpecial) specialLine++;
    }

    if(specialLine == 1) {
        for(int j = 4; j >= 0; j--) {
            for(int col = 0; col < 4; col++) {
                greenBoard[j + 1][col] = greenBoard[j][col];
            }
            
        }

        for(int col = 0; col < 4; col++) {
            greenBoard[0][col] = EMPTY;
        }
    }
    if(specialLine == 2) {
        for(int j = 3; j >= 0; j--) {
            for(int col = 0; col < 4; col++) {
                greenBoard[j + 2][col] = greenBoard[j][col];
            }
        }

        for(int col = 0; col < 4; col++) {
            greenBoard[0][col] = EMPTY;
            greenBoard[1][col] = EMPTY;
        }
    }

    
}

void putGreen(int t, int row, int col) {
    // 블록 놓기
    if(t != 2) {
        int i;
        for(i = 0; i < 6; i++) {
            if(greenBoard[i][col] == BLOCK) {
                i--;  // 블럭이 놓여야 할 위치
                break;
            }
        }

        if(i == 6) {
            i = 5;
        }

        greenBoard[i][col] = BLOCK;
        if(t == 3) greenBoard[i - 1][col] = BLOCK;
    }
    else {
        int i;
        for(i = 0; i < 6; i++) {
            if(greenBoard[i][col] == BLOCK || greenBoard[i][col + 1] == BLOCK) {
                i--;  // 블럭이 놓여야 할 위치
                break;
            }
        }

        if(i == 6) {
            i = 5;
        }

        greenBoard[i][col] = BLOCK;
        greenBoard[i][col + 1] = BLOCK;
    }
}


int getAll() {
    int res = 0;

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 6; j++) {
            res += blueBoard[i][j];
        }
    }

    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 4; j++) {
            res += greenBoard[i][j];
        }
    }

    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int n;
    cin >> n;
    while(n--) {
        process();
    }

    cout << score << "\n" << getAll();
    

    return 0;
}