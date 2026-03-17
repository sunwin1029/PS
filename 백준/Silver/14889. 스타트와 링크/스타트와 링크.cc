#include <bits/stdc++.h>
#define TEAMLINK 0
#define TEAMSTART 1
using namespace std;

int n;
int res = INT_MAX;
vector<vector<int>> arr;
vector <int> team;

int getDif() {
    int teamLink = 0;
    int teamStart = 0;

    for(int i = 0; i < n; i++) {
        // 무슨 팀인지
        int side = team[i];

        for(int j = 0; j < n; j++) {
            // 동일인물에 대한 시너지 제거
            if(i == j) continue;

            // 같은 팀일 경우 점수 추가
            if(side == team[j]) {
                if(side == TEAMLINK) {
                    teamLink += arr[i][j];
                } else {
                    teamStart += arr[i][j];
                }
            }
        }
    }

    return abs(teamLink - teamStart);
}

void backTracking(int index, int teamLinkAmt, int teamStartAmt) {
    if(index == n) {
        res = min(res, getDif());
        return;
    }
    if(teamLinkAmt >= n / 2) {
        for(int i = index; i < n; i++) {
            team[i] = TEAMSTART;
        }
        res = min(res, getDif());
        return;
    }
    if(teamStartAmt >= n / 2) {
        for(int i = index; i < n; i++) {
            team[i] = TEAMLINK;
        }
        res = min(res, getDif());
        return;
    }
    else {
        team[index] = TEAMLINK;
        backTracking(index + 1, teamLinkAmt + 1, teamStartAmt);

        team[index] = TEAMSTART;
        backTracking(index + 1, teamLinkAmt, teamStartAmt + 1);
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    arr.resize(n, vector<int>(n));
    team.resize(n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    backTracking(0, 0, 0);

    cout << res << "\n";


    return 0;
}