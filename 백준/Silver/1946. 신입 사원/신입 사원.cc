#include <bits/stdc++.h>
using namespace std;

bool Compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first; 
}

void program() {
    int n;
    cin >> n;

    vector <pair <int, int>> e(n);

    for(int i = 0; i < n; i++) {
        cin >> e[i].first >> e[i].second;
    }

    sort(e.begin(), e.end(), Compare);

    int tmp = e[0].second;
    int res = 0;

    for(int i = 0; i < n; i++) {
        if(e[i].second > tmp) continue;
        tmp = min(e[i].second, tmp);
        res++;
    }


    cout << res << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--) program();

    return 0;
}