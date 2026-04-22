#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, long long> Point;

int ccw(Point a, Point b, Point c) {
    long long temp = a.first * b.second + b.first * c.second + c.first * a.second;
    temp -= (b.first * a.second + c.first * b.second + a.first * c.second);

    if(temp > 0) return 1;
    else if(temp < 0) return -1;
    else return 0;
}

bool isIntersect(Point a, Point b, Point c, Point d) {
    int ab_c = ccw(a, b, c);
    int ab_d = ccw(a, b, d);
    int cd_a = ccw(c, d, a);
    int cd_b = ccw(c, d, b);

    if(ab_c * ab_d == 0 && cd_a * cd_b == 0) {
        if(a > b) swap(a, b);
        if(c > d) swap(c, d);

        return a <= d && c <= b; 
    }
    return ab_c * ab_d <= 0 && cd_a * cd_b <= 0;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Point a, b, c, d;

    cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second >> d.first >> d.second;

    if(isIntersect(a, b, c, d)) {
        cout << "1\n";
    }
    else {
        cout << "0\n";
    }

    return 0;
}