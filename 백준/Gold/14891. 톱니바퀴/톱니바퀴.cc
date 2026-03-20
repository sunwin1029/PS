#include <bits/stdc++.h>
#define NSTATE 0
#define SSTATE 1
#define CLOCK 1
#define REVERSE -1
#define NONE 0
using namespace std;

class Gear {
   public:
    int gearState[8];  // Gear 8개의 상태
    int gearTopIndex;  // 어느 부분이 12시 방향에 있는지

    void init() {
        string s;
        cin >> s;
        for(int i = 0; i < 8; i++) {
            gearState[i] = s[i] - '0';
        }
        gearTopIndex = 0;
    }

    // 3시 방향 상태 알아내는 함수
    int getRight() { return gearState[(gearTopIndex + 2) % 8]; }

    // 9시 방향 상태 알아내는 함수
    int getLeft() { return gearState[(gearTopIndex + 6) % 8]; }

    // 회전하는 함수
    void rotate(int dir) {
        if(dir == CLOCK) {
            gearTopIndex = (gearTopIndex + 7) % 8;
        } else if(dir == REVERSE) {
            gearTopIndex = (gearTopIndex + 1) % 8;
        }
    }

    int getTop() { return gearState[gearTopIndex]; }
};

Gear gear[8];

void progress(int gearIndex, int dir, int progressDir) {
    if(gearIndex > 3 || gearIndex < 0) return;

    if(progressDir >= 0) {
        if(gear[gearIndex].getRight() != gear[gearIndex + 1].getLeft()) {
            progress(gearIndex + 1, dir * -1, 1);
        }
    } 
    if(progressDir <= 0) {
        if(gear[gearIndex].getLeft() != gear[gearIndex - 1].getRight()) {
            progress(gearIndex - 1, dir * -1, -1);
        }
    }
    gear[gearIndex].rotate(dir);
}


void progress(int gearNum, int dir) { int gearIndex = gearNum - 1; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 0; i < 4; i++) {
        gear[i].init();
    }

    int n;

    cin >> n;

    for(int i = 0; i < n; i++) {
        int gearNum, direction;
        cin >> gearNum >> direction;

        progress(gearNum - 1, direction, 0);
    }

    int res = 0;

    for(int i = 0; i < 4; i++) {
        if(gear[i].getTop() == SSTATE) {
            res += 1 << i;
        }
    }

    cout << res << "\n";

    return 0;
}