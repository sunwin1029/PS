#include <bits/stdc++.h>
using namespace std;

int n;
vector <pair <long long, long long>> dot(10100);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++) {
        pair<int, int> tmp;
        cin >> tmp.first >> tmp.second;

        dot[i] = tmp;
    }
    dot[n] = dot[0];

    long long toRightDown = 0;
    long long toLeftDown = 0;

    for(int i = 0; i < n; i++) {
        toRightDown += dot[i].first * dot[i + 1].second;
        toLeftDown += dot[i].second * dot[i + 1].first;
    }

    double res = llabs(toRightDown - toLeftDown) / 2.0;

    cout << fixed << setprecision(1) << res << "\n";

    return 0;
}