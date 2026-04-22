#include <bits/stdc++.h>
#define Point pair<long long, long long>
using namespace std;

bool check_ccw(Point a, Point b, Point c) {
    long long temp = a.first * b.second + b.first * c.second + c.first * a.second;
    temp -= (b.first * a.second + c.first * b.second + a.first * c.second);

    return temp > 0 ? true : false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<long long, long long>> point(n);
    set <pair <long long, long long>> res_point;

    for(int i = 0; i < n; i++) {
        cin >> point[i].first >> point[i].second;
    }

    sort(point.begin(), point.end());

    stack<pair<long long, long long>> s;

    for(int i = 0; i < n; i++) {
        if(s.size() < 2) {
            s.push(point[i]);
            continue;
        }

        while(true) {
            if(s.size() < 2) {
                s.push(point[i]);
                break;
            }
            pair<long long, long long> current_point = s.top();
            s.pop();
            pair<long long, long long> prev_point = s.top();

            if(check_ccw(prev_point, current_point, point[i])) {
                s.push(current_point);
                s.push(point[i]);
                break;
            }
        }
    }

    while(s.size() > 0) {
        res_point.insert(s.top());
        s.pop();
    }

    for(int i = n - 1; i >= 0; i--) {
        if(s.size() < 2) {
            s.push(point[i]);
            continue;
        }

        while(true) {
            if(s.size() < 2) {
                s.push(point[i]);
                break;
            }
            pair<long long, long long> current_point = s.top();
            s.pop();
            pair<long long, long long> prev_point = s.top();

            if(check_ccw(prev_point, current_point, point[i])) {
                s.push(current_point);
                s.push(point[i]);
                break;
            }
        }
    }

    while(s.size() > 0) {
        res_point.insert(s.top());
        s.pop();
    }

    cout << res_point.size() << "\n";

    return 0;
}