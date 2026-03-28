#include <bits/stdc++.h>
using namespace std;

int drow[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dcol[8] = {0, 1, 1, 1, 0, -1, -1, -1};

class FireBall {
   public:
    int m;
    int d;
    int s;
    bool move;

    FireBall(int m, int d, int s)
        : m(m), d(d), s(s), move(false) {}
    
};

vector <vector <queue <FireBall>>> board;
int n, m, k;



void moveProcess(int r, int c) {
    while(!board[r][c].empty()) {
        FireBall tmp = board[r][c].front();

        if(tmp.move == true) break; // 이미 이동한 파이어볼일 경우

        board[r][c].pop(); // 해당 위치에서 제거

        int newRow, newCol;

        // 새로운 위치
        newRow = ((r + drow[tmp.d] * tmp.s) % n + n) % n;
        newCol = ((c + dcol[tmp.d] * tmp.s) % n + n) % n;
        tmp.move = true;

        board[newRow][newCol].push({tmp});
    }
}

void combineProcess(int r, int c) {
    FireBall newFireBall(0, 0, 0);
    queue <FireBall> &ballState = board[r][c];

    int newM = 0;
    int newS = 0;
    int newD;
    int amt = ballState.size();

    // 파이어볼이 없는 경우
    if(ballState.size() == 0) return;
    // 파이어볼이 1개만 있는 경우
    if(ballState.size() == 1) {
        ballState.front().move = false;
        return;
    }
    
    newD = (ballState.front().d) % 2;

    // 같은 칸에 있는 파이어볼은 모두 하나로 합쳐진다.
    while(!ballState.empty()) {
        FireBall tmp = ballState.front();
        ballState.pop();

        if(newD == -1 || tmp.d % 2 != newD) {
            newD = -1;
        }

        newM += tmp.m;
        newS += tmp.s;
    }

    // 질량은 ⌊(합쳐진 파이어볼 질량의 합)/5⌋이다.
    newM = newM / 5;
    // 속력은 ⌊(합쳐진 파이어볼 속력의 합)/(합쳐진 파이어볼의 개수)⌋이다.
    newS = newS / amt;
    // 합쳐지는 파이어볼의 방향이 모두 홀수이거나 모두 짝수이면, 방향은 0, 2, 4,
    // 6이 되고, 그렇지 않으면 1, 3, 5, 7이 된다.
    newD = (newD == -1) ? 1 : 0;

    // 질량이 0인 파이어볼은 소멸되어 없어진다.
    if(newM == 0) return;

    // 공추가
    for(int i = 0; i < 4; i++) {
        ballState.push(FireBall(newM, i * 2 + newD, newS));
    }
}


void allProcess(int t) {
    while(t--) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                moveProcess(i, j);
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
               combineProcess(i, j);
            }
        }
    }

    int allMass = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            while(!board[i][j].empty()) {
                allMass += board[i][j].front().m;
                board[i][j].pop();
            }
        }
    }

    cout << allMass << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    board.resize(n, vector<queue<FireBall>>(n));

    for(int i = 0; i < m; i ++) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;

        board[r - 1][c - 1].push({m, d, s});
    }

    allProcess(k);

    return 0;
}