#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y, d, t;
    cout << fixed;
    cout.precision(10);

    cin >> x >> y >> d >> t;

    double res = sqrt(x * x + y * y);

    double direct_distance = res;

    int jump_move = direct_distance / (double)d;

    double jump_move_time = jump_move * t + (direct_distance - jump_move * d);

    double jump_back_move_time = (jump_move + 1) * t + ((jump_move + 1) * d - direct_distance);

    double only_jump_time;

    if(d > direct_distance) {
        only_jump_time = 2 * t;
    }
    else {
        only_jump_time = (jump_move + 1) * t;
    }

    res = min({res, jump_move_time, jump_back_move_time, only_jump_time});

    cout << res << "\n";

    return 0;
}