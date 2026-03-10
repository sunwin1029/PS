#include <bits/stdc++.h>
#define Point pair<long long, long long>
using namespace std;

int ccw(Point a, Point b, Point c) {
    long long temp =
        a.first * b.second + b.first * c.second + c.first * a.second;
    temp -= (b.first * a.second + c.first * b.second + a.first * c.second);

    if(temp > 0) {
        return 1;
    } else if(temp < 0) {
        return -1;
    } else {
        return 0;
    }
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

int Find(int x, vector<int>& v) {
    if(v[x] == x) return x;
    return v[x] = Find(v[x], v);
}

bool Union(int a, int b, vector<int>& v) {
    a = Find(a, v);
    b = Find(b, v);

    if(a == b) return false;

    v[b] = a;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<Point, Point>> arr(n + 1);
    vector<int> group(n + 1);
    vector<int> group_member_num(n + 1, 0);
    int group_num = n;
    int max_group = 0;

    for(int i = 1; i <= n; i++) {
        cin >> arr[i].first.first >> arr[i].first.second >>
            arr[i].second.first >> arr[i].second.second;
        group[i] = i;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            if(isIntersect(arr[i].first, arr[i].second, arr[j].first,
                           arr[j].second)) {
                if(Union(i, j, group)) {
                    group_num--;
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        group_member_num[Find(i, group)]++;
    }

    for(int i = 1; i <= n; i++) {
        max_group = max(max_group, group_member_num[i]);
    }

    cout << group_num << "\n" << max_group << "\n";

    return 0;
}