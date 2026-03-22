#include <bits/stdc++.h>
#define W 0
#define Y 1
#define R 2
#define O 3
#define G 4
#define B 5
#define UP 0
#define DOWN 1
#define FRONT 2
#define BACK 3
#define LEFT 4
#define RIGHT 5
#define CLOCK 1
#define REVERSE -1
using namespace std;

int t;
vector <vector <vector <int>>> cube(6, vector<vector<int>>(3, vector<int>(3)));

// 큐브 초기화
void initCube() {
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                cube[i][j][k] = i;
            }
        }
    }
}

// 색상 변환
char convertColor(int color) {
    switch(color) {
        case W:
            return 'w';
            break;
        case Y:
            return 'y';
            break;
        case R:
            return 'r';
            break;
        case O:
            return 'o';
            break;
        case G:
            return 'g';
            break;
        case B:
            return 'b';
            break;
    }

    return '0';
}

vector <int> getRow(int side, int r) {
    vector <int> tmp(3);

    for(int i = 0; i < 3; i++) {
        tmp[i] = cube[side][r][i];
    }

    return tmp;
}

vector <int> getCol(int side, int c) {
    vector <int> tmp(3);

    for(int i = 0; i < 3; i++) {
        tmp[i] = cube[side][i][c];
    }

    return tmp;
}

void setRow(int side, int r, const vector <int> &v) {
    for(int i = 0; i < 3; i++) {
        cube[side][r][i] = v[i];
    }
}

void setCol(int side, int c, const vector <int> &v) {
    for(int i = 0; i < 3; i++) {
        cube[side][i][c] = v[i];
    }
}

vector <int> reverseVector(vector <int> v) {
    reverse(v.begin(), v.end());
    return v;
}

void rotateSide(int side, int dir) {
    vector<vector<int>> tmpSide(3, vector<int>(3));

    tmpSide = cube[side];

    if(dir == CLOCK) {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                cube[side][i][j] = tmpSide[2 - j][i];
            }
        }
    } else if(dir == REVERSE) {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                cube[side][i][j] = tmpSide[j][2 - i];
            }
        }
    }
}

void rotateUp(int dir) {
    vector <int> f = getRow(FRONT, 0);
    vector <int> r = getRow(RIGHT, 0);
    vector <int> b = getRow(BACK, 0);
    vector <int> l = getRow(LEFT, 0);

    rotateSide(UP, dir);

    if(dir == CLOCK) {
        setRow(FRONT, 0, r);
        setRow(RIGHT, 0, b);
        setRow(BACK, 0, l);
        setRow(LEFT, 0, f);
    }
    else if(dir == REVERSE) {
        setRow(FRONT, 0, l);
        setRow(RIGHT, 0, f);
        setRow(BACK, 0, r);
        setRow(LEFT, 0, b);
    }
}

void rotateDown(int dir) {
    vector <int> f = getRow(FRONT, 2);
    vector <int> r = getRow(RIGHT, 2);
    vector <int> b = getRow(BACK, 2);
    vector <int> l = getRow(LEFT, 2);

    rotateSide(DOWN, dir);

    if(dir == CLOCK) {
        setRow(FRONT, 2, l);
        setRow(RIGHT, 2, f);
        setRow(BACK, 2, r);
        setRow(LEFT, 2, b);
    }
    else if(dir == REVERSE) {
        setRow(FRONT, 2, r);
        setRow(RIGHT, 2, b);
        setRow(BACK, 2, l);
        setRow(LEFT, 2, f);
    }
}

void rotateFront(int dir) {
    vector <int> u = getRow(UP, 2);
    vector <int> r = getCol(RIGHT, 0);
    vector <int> d = getRow(DOWN, 0);
    vector <int> l = getCol(LEFT, 2);

    rotateSide(FRONT, dir);

    if(dir == CLOCK) {
        setCol(RIGHT, 0, u);
        setRow(DOWN, 0, reverseVector(r));
        setCol(LEFT, 2, d);
        setRow(UP, 2, reverseVector(l));
    }
    else if(dir == REVERSE) {
        setCol(RIGHT, 0, reverseVector(d));
        setRow(UP, 2, r);
        setCol(LEFT, 2, reverseVector(u));
        setRow(DOWN, 0, l);
    }
}

void rotateBack(int dir) {
    vector<int> u = getRow(UP, 0);
    vector<int> r = getCol(RIGHT, 2);
    vector<int> d = getRow(DOWN, 2);
    vector<int> l = getCol(LEFT, 0);

    rotateSide(BACK, dir);

    if(dir == CLOCK) {
        setCol(RIGHT, 2, reverseVector(d));
        setRow(UP, 0, r);
        setCol(LEFT, 0, reverseVector(u));
        setRow(DOWN, 2, l);

    } else if(dir == REVERSE) {
        setCol(RIGHT, 2, u);
        setRow(DOWN, 2, reverseVector(r));
        setCol(LEFT, 0, d);
        setRow(UP, 0, reverseVector(l));
    }
}

void rotateLeft(int dir) {
    vector<int> u = getCol(UP, 0);
    vector<int> f = getCol(FRONT, 0);
    vector<int> d = getCol(DOWN, 0);
    vector<int> b = getCol(BACK, 2);

    rotateSide(LEFT, dir);

    if(dir == CLOCK) {
        setCol(FRONT, 0, u);
        setCol(DOWN, 0, f);
        setCol(BACK, 2, reverseVector(d));
        setCol(UP, 0, reverseVector(b));
    }
    else if(dir == REVERSE) {
        setCol(FRONT, 0, d);
        setCol(DOWN, 0, reverseVector(b));
        setCol(BACK, 2, reverseVector(u));
        setCol(UP, 0, f);
    }
}


void rotateRight(int dir) {
    vector<int> u = getCol(UP, 2);
    vector<int> f = getCol(FRONT, 2);
    vector<int> d = getCol(DOWN, 2);
    vector<int> b = getCol(BACK, 0);

    rotateSide(RIGHT, dir);

    if(dir == CLOCK) {
        setCol(FRONT, 2, d);
        setCol(DOWN, 2, reverseVector(b));
        setCol(BACK, 0, reverseVector(u));
        setCol(UP, 2, f);
    } else if(dir == REVERSE) {
        setCol(FRONT, 2, u);
        setCol(DOWN, 2, f);
        setCol(BACK, 0, reverseVector(d));
        setCol(UP, 2, reverseVector(b));
    }
}

void program() {
    int n;
    cin >> n;

    initCube();

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int dir;
        int side;

        dir = (s[1] == '+' ? CLOCK : REVERSE);

        switch(s[0]) {
            case 'U':
                rotateUp(dir);
                break;
            case 'D':
                rotateDown(dir);
                break;
            case 'F':
                rotateFront(dir);
                break;
            case 'B':
                rotateBack(dir);
                break;
            case 'L':
                rotateLeft(dir);
                break;
            case 'R':
                rotateRight(dir);
                break;
        }
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << convertColor(cube[UP][i][j]);
        }
        cout << "\n";
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        program();
    }


    return 0;
}