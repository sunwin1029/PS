#include <bits/stdc++.h>
using namespace std;

struct Compare{
    bool operator()(int &a, int &b) {
        if(a == 0) return true;
        if(b == 0) return false;
        if(a < 0 && b < 0) return a > b;
        return a < b;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    priority_queue <int, vector<int>, Compare> pq;

    cin >> n;

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }

    long long res = 0;

    while(!pq.empty()) {
        int tmp1 = pq.top();
        pq.pop();

        if(pq.empty()) {
            res += tmp1;
            break;
        } 

        int tmp2 = pq.top();
        pq.pop();

        if(tmp1 > 0 && tmp2 == 0) {
            res += tmp1;
            continue;
        }

        if(tmp1 * tmp2 < 0) {
            res += tmp1;
            pq.push(tmp2);
            continue;
        }

        if(tmp1 > 0 && tmp2 == 1) {
            res += tmp1;
            res += tmp2;
            continue;
        }

        res += tmp1 * tmp2;
    }

    cout << res << "\n";


    return 0;
}