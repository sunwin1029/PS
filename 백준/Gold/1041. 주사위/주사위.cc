#include <bits/stdc++.h>
using namespace std;

long long n;
long long dice[6];
long long side1_min;
long long side2_min;
long long side3_min;
long long side1_max = 0;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    side1_min = INT_MAX;
    side2_min = INT_MAX;
    side3_min = INT_MAX;

    for(int i = 0; i < 6; i++) {
        cin >> dice[i];
        side1_max = max(side1_max, dice[i]);
        side1_min = min(side1_min, dice[i]);
    }

    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            if(i + j == 5 || i == j) continue;
            side2_min = min(side2_min, dice[i] + dice[j]); 
            for(int k = 0; k < 6; k++) {
                if(i == k || j == k || j + k == 5 || i + k == 5) continue;
                side3_min = min(side3_min, dice[i] + dice[j] + dice[k]);
            }
        }
    }

    long long res = 0;

    // cout << side1_min << " " << side2_min << " " << side3_min << "\n";

    if(n == 1) {
        for(int i = 0; i < 6; i++) {
            res += dice[i];
        }
        res -= side1_max;
    }
    else {
        res += 4 * side3_min;
        res += (8 * n - 12) * side2_min;
        res += (5 * n * n - 16 * n + 12) * side1_min;
    }

    cout << res << "\n";

    return 0;
}