#include <bits/stdc++.h>
using namespace std;

struct Compare {
    bool operator() (int &a, int &b) {
        return abs(a) < abs(b);
    }
}; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    priority_queue <int, vector<int>, Compare> minusBook;
    priority_queue <int, vector<int>, Compare> plusBook;

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        if(tmp > 0) plusBook.push(tmp);
        else minusBook.push(tmp);
    }

    int mostFarLoc = 0;
    int res = 0;

    while(!plusBook.empty()) {
        int tmp = plusBook.top();
        for(int i = 0; i < m; i++) {
            if(plusBook.empty()) break;
            plusBook.pop();
        }

        mostFarLoc = max(mostFarLoc, abs(tmp));
        res += abs(tmp) * 2;
    }

    while(!minusBook.empty()) {
        int tmp = minusBook.top();
        for(int i = 0; i < m; i++) {
            if(minusBook.empty()) break;
            minusBook.pop();
        }

        mostFarLoc = max(mostFarLoc, abs(tmp));
        res += abs(tmp) * 2;
    }

    res -= mostFarLoc;

    cout << res << "\n";


    return 0;
}