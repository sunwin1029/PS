#include <bits/stdc++.h>
#define ENDPOINT 21
#define CENTERPOINT 30
#define FIRSTSHORTCUT 5
#define SECONDSHORTCUT 10
#define THIRDSHORTCUT 15
#define DESTINATION 100
#define POINT piece[pieceNum]
using namespace std;

const int step = 9;
const int choice = 4;
int res = INT_MIN;
vector<int> board(200);
vector<int> play(10);
// vector<int> piece(4);

int move(int pieceNum, int dis, vector<int>& piece) {
    int index = piece[pieceNum];
    if(index == ENDPOINT) return INT_MIN;

    // 지름길에서 시작하는 경우
    if(index == FIRSTSHORTCUT) {
        POINT = 22;
        dis--;
    } else if(index == SECONDSHORTCUT) {
        POINT = 25;
        dis--;
    } else if(index == THIRDSHORTCUT) {
        POINT = 27;
        dis--;
    } 

    // 이동 로직
    for(int i = 0; i < dis; i++) {
        if(POINT == ENDPOINT) {
            break;
        }
        if(POINT == 24 || POINT == 26) {
            POINT = CENTERPOINT;
            continue;
        }
        if(POINT == 32) {
            POINT = 20;
            continue;
        }

        POINT = POINT + 1;
    }

    // 해당 위치에 이미 말이 있는지 확인
    if(POINT != ENDPOINT) {
        for(int i = 0; i < 4; i++) {
            if(i == pieceNum) continue;
            if(POINT == piece[i]) return INT_MIN;
        }
    }
    

    return board[POINT];
}

void process(int mask) {
    int sum = 0;
    vector<int> piece(4, 0);

    // 처음에 어떤 기물이 움직여도 상관 없음
    piece[0] = play[0];
    sum += board[play[0]];

    // 기물 움직이기
    for(int i = 0; i < step; i++) {
        int choice = mask % 4;
        mask /= 4;

        int tmp = move(choice, play[i + 1], piece);

        // 중복된 경우
        if(tmp == INT_MIN) {
            sum = INT_MIN;
            break;
        }

        sum += tmp;
    }

    res = max(res, sum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 1; i <= 20; i++) {
        board[i] = i * 2;
    }

    for(int i = 0; i < 10; i++) {
        cin >> play[i];
    }
    // 첫번째 지름길 길목
    board[22] = 13;
    board[23] = 16;
    board[24] = 19;

    // 두번째 지름길 길목
    board[25] = 22;
    board[26] = 24;

    // 세번째 지름길 길목
    board[27] = 28;
    board[28] = 27;
    board[29] = 26;

    board[CENTERPOINT] = 25;

    // 중간 지점에서 마지막까지
    board[31] = 30;
    board[32] = 35;

    int cases = 1;
    for(int i = 0; i < 9; i++) cases *= 4;

    for(int i = 0; i < cases; i++) {
        process(i);
    }

    cout << res << "\n";

    return 0;
}