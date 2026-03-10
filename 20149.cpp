#include <bits/stdc++.h>
#define Point pair<long long, long long>
using namespace std;

int ccw(Point a, Point b, Point c) {
    long long temp = a.first * b.second + b.first * c.second + c.first * a.second;
    temp -= (b.first * a.second + c.first * b.second + a.first * c.second);

    if(temp > 0) {
        return 1;
    }
    else if(temp < 0) {
        return -1;
    }
    else {
        return 0;
    }
}

int isIntersect(Point &a, Point &b, Point &c, Point &d) {
    int ab_c = ccw(a, b, c);
    int ab_d = ccw(a, b, d);
    int cd_a = ccw(c, d, a);
    int cd_b = ccw(c, d, b);

    if(ab_c == 0 && ab_d == 0 && cd_a == 0 && cd_b == 0) {
        if(a > b) swap(a, b);
        if(c > d) swap(c, d);

        Point leftMax = max(a, c);
        Point rightMin = min(b, d);

        if(leftMax == rightMin) return 2;
        if(leftMax > rightMin) return -1;
        return 0;
    }

    return (ab_c * ab_d <= 0 && cd_a * cd_b <= 0) ? 1 : -1;
}

pair <long double, long double> returnIntersectPoint(Point a, Point b, Point c, Point d) {
    long double A1 = b.second - a.second;
    long double B1 = a.first - b.first;
    long double C1 = A1 * a.first + B1 * a.second;

    long double A2 = d.second - c.second;
    long double B2 = c.first - d.first;
    long double C2 = A2 * c.first + B2 * c.second;

    long double det = A1 * B2 - A2 * B1;

    long double x = (C1 * B2 - C2 * B1) / det;
    long double y = (A1 * C2 - A2 * C1) / det;

    return {x, y};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed;
    cout.precision(9);

    Point a, b, c, d;

    cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second >> d.first >> d.second;

    
    int intersectRes = isIntersect(a, b, c, d);

    cout << (intersectRes > -1 ? 1 : 0) << "\n";


    if(intersectRes > 0) {
        if(intersectRes == 2) {
            Point tmp = max(a, c);
            cout << tmp.first << " " << tmp.second << "\n";
        }
        else {
            pair<long double, long double> p = returnIntersectPoint(a, b, c, d);
            cout << p.first << " " << p.second << "\n";
        }
    
    }


    return 0;
}