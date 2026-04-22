#include <bits/stdc++.h>
#define CLOCK 0
#define REVERSE 1
#define NO_NUM INT_MIN
using namespace std;

int n, m, t;
vector<vector<int>> circleBoard;
vector<int> startIndex;
vector<tuple<int, int, int>> rotateMethod;

void eliminateProcess() {
    bool eliminate = false;
    // 같은 판에서 인접한 숫자 지우기

    vector <pair <int, int>> haveToErase;

    // 원판에 수가 남아 있으면, 인접하면서 수가 같은 것을 모두 찾는다
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            bool isNeighborEliminated = false;
            int tmpIndex = (j + startIndex[i]) % m;
            int tmpNum = circleBoard[i][tmpIndex % m];

            if(tmpNum == NO_NUM) continue;

            // 시계방향 기준으로 쭉 일치하는거 지우기
            int k = 1;
            while(k < m && circleBoard[i][(tmpIndex + k) % m] == tmpNum) {
                isNeighborEliminated = true;
                haveToErase.push_back({i, (tmpIndex + k) % m});
                k++;
            }
            // 시계방향 기준 뒤쪽
            k = 1;
            while(k < m && circleBoard[i][(tmpIndex + m - k) % m] == tmpNum) {
                isNeighborEliminated = true;
                haveToErase.push_back({i, (tmpIndex + m - k ) % m});
                k++;
            }

            if(isNeighborEliminated) {
                eliminate = true;
                haveToErase.push_back({i, tmpIndex});
                // circleBoard[i][j] = NO_NUM;
            }
        }
    }

    // 앞뒤판끼리 인접한 숫자 지우기
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            // 현재 원판의 수
            int tmpNum = circleBoard[j][(i + startIndex[j]) % m];
            // 해당 프로세스에서 현재 위치의 수가 사라져야 하는가?
            bool isVerticalEliminated = false;

            // 숫자 없음
            if(tmpNum == NO_NUM) continue;

            // 비교용 인덱스
            int k = j + 1;

            // 연속해서 숫자가 동일한 경우
            while(k < n && tmpNum == circleBoard[k][(i + startIndex[k]) % m]) {
                isVerticalEliminated = true;
                circleBoard[k][(i + startIndex[k]) % m] = NO_NUM;
                k++;
            }

            // 한개라도 사라진 경우, 원래 위치도 사라져야함
            if(isVerticalEliminated) {
                eliminate = true;
                haveToErase.push_back({j, (i + startIndex[j]) % m});
                // circleBoard[j][(i + startIndex[j]) % m] = NO_NUM;
            }
        }
    }

    if(eliminate) {
        for(int i = 0; i < haveToErase.size(); i++) {
            int r = haveToErase[i].first;
            int c = haveToErase[i].second;

            circleBoard[r][c] = NO_NUM;
        }
        return;
    }

    // 없는 경우에는 원판에 적힌 수의 평균을 구하고, 평균보다 큰 수에서 1을
    // 빼고, 작은 수에는 1을 더한다.
    int sum = 0;
    int amt = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(circleBoard[i][j] == NO_NUM) continue;

            sum += circleBoard[i][j];
            amt++;
        }
    }

    if(amt) {
        double avg = (double)sum / (double)amt;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(circleBoard[i][j] == NO_NUM) continue;

                if(circleBoard[i][j] > avg)
                    circleBoard[i][j]--;
                else if(circleBoard[i][j] < avg)
                    circleBoard[i][j]++;
            }
        }
    }
}

int getTotal() {
    int res = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(circleBoard[i][j] == NO_NUM) continue;

            res += circleBoard[i][j];
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> t;

    circleBoard.resize(n, vector<int>(m));
    startIndex.resize(n);
    rotateMethod.resize(t);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> circleBoard[i][j];
        }
    }

    for(int i = 0; i < t; i++) {
        cin >> get<0>(rotateMethod[i]) >> get<1>(rotateMethod[i]) >>
            get<2>(rotateMethod[i]);
        
    }

    for(int i = 0; i < t; i++) {
        int x = get<0>(rotateMethod[i]);
        int d = get<1>(rotateMethod[i]);
        int k = get<2>(rotateMethod[i]);

        // start index 이동을 통한 회전
        if(d == REVERSE) {
            for(int j = 0; j < n; j++) {
                if((j + 1) % x == 0) {
                    startIndex[j] = (startIndex[j] + k) % m;
                }
            }
        } else if(d == CLOCK) {
            for(int j = 0; j < n; j++) {
                if((j + 1) % x == 0) {
                    startIndex[j] = (startIndex[j] + m - k) % m;
                }
            }
        }

        eliminateProcess();
        // 같은 판에서 인접한 숫자 지우기
    }

    cout << getTotal() << "\n";

    return 0;
}