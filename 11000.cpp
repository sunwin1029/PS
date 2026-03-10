#include <bits/stdc++.h>
using namespace std;

bool Compare(const pair <int, int> &a, const pair <int, int> &b) {
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int res = 0;
    vector <pair <int, int>> c;
    priority_queue<int, vector<int>, greater<int>> classroom;

    cin >> n;

    for(int i = 0; i < n; i++) {
        pair <int, int> tmp;
        cin >> tmp.first >> tmp.second;

        c.push_back(tmp);
    }

    sort(c.begin(), c.end(), Compare);
    classroom.push(INT_MAX);

    for(int i = 0; i < n; i++) {
        int end_earliest = classroom.top();

        if(c[i].first < end_earliest) {
            res++;
            classroom.push(c[i].second);
        }
        else {
            classroom.pop();
            classroom.push(c[i].second);
        }
    }

    cout << res << "\n";
    가나다라마

    return 0;
}