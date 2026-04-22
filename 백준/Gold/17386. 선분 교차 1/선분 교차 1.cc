#include <bits/stdc++.h>
#define llp pair<long long, long long>
using namespace std;

int ccw(llp a, llp b, llp c) {
    long long op = (b.first - a.first) * (c.second - a.second) -
             (b.second - a.second) * (c.first - a.first);
    if(op > 0) return 1;
    if(op < 0) return -1;
    return 0;
}

bool intersect(llp a, llp b, llp c, llp d) {
    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);

    if(ab == 0 && cd == 0) {
        if(a > b) swap(a, b);
        if(c > d) swap(c, d);

        return !(b < c || d < a);
    }

    return (ab <= 0 && cd <= 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    llp a, b, c, d;

    cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second >>
        d.first >> d.second;

    if(intersect(a, b, c, d)) {
        cout << "1\n";
    } else {
        cout << "0\n";
    }

    return 0;
}