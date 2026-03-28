#include <bits/stdc++.h>
using namespace std;

int n, k;
int stateZeroNum = 0;
vector<pair<int, bool>> belt;  // {내구도, 로봇 존재 여부}
int startPoint;
int endPoint;

bool process() {
    // 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
    startPoint = (startPoint - 1 + 2 * n) % (2 * n);
    endPoint = (endPoint - 1 + 2 * n) % (2 * n);

    if(belt[endPoint].second) {
        belt[endPoint].second = false;
    }

    // 로봇 이동
    for(int i = 0; i < n - 1; i++) {
        int index = (endPoint - i + 2 * n) % (2 * n);
        int beforeIndex = (index - 1 + 2 * n) % (2 * n);

        if(belt[index].first > 0 && !belt[index].second &&
           belt[beforeIndex].second) {
            belt[index].second = true;
            belt[index].first--;
            belt[beforeIndex].second = false;

            if(belt[index].first == 0) {
                stateZeroNum++;
            }
        }
    }

    // 도착지 로봇 제거
    if(belt[endPoint].second) {
        belt[endPoint].second = false;
    }


    // 로봇 올리기
    if(belt[startPoint].first > 0 && !belt[startPoint].second) {
        belt[startPoint].first--;
        belt[startPoint].second = true;

        if(belt[startPoint].first == 0) {
            stateZeroNum++;
        }
    }

    // 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다.
    if(stateZeroNum >= k) {
        return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    startPoint = 0;
    endPoint = n - 1;

    belt.resize(2 * n, {0, false});

    for(int i = 0; i < n * 2; i++) {
        cin >> belt[i].first;
    }

    int res = 1;

    while(process()) {
        res++;
    }

    cout << res << "\n";

    return 0;
}