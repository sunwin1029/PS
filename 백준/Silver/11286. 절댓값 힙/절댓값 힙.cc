#include <bits/stdc++.h>
using namespace std;

struct Compare {
    bool operator()(const int &a, const int &b) {
        if(abs(a) == abs(b)) return a > b;
        else return abs(a) > abs(b);
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    priority_queue <int, vector<int>, Compare> pq; 
    cin >> x;



    for(int i = 0; i < x; i++) {
        int tmp;
        cin >> tmp;

        if(tmp == 0) {
            if(pq.empty()) {
                cout << "0\n";
                continue;
            }
            else {
                cout << pq.top() << "\n";
                pq.pop();
                continue;
            }
        }
        else {
            pq.push(tmp);
        }
    }

    return 0;
}