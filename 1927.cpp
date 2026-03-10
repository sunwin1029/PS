#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    priority_queue<int, vector<int>, greater<int>> q;

    cin >> n;

    int t;
    while(n--) {
        cin >> t;

        if(t == 0) {
            if(q.empty()) {
                cout << "0\n";
                continue;
            }
            else {
                cout << q.top() << "\n";
                q.pop();
            }
        }
        else {
            q.push(t);
        }
    }


    return 0;
}