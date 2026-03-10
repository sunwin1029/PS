#include <bits/stdc++.h>
#define Pair pair<int, int>
using namespace std;

struct Compare {
    bool operator() (int &a, int &b) {
        return a > b;
    }
};

void program() {
    int n, m;
    cin >> n >> m;
    int res = 0;

    priority_queue <int, vector<int>, Compare> list;
    vector <Pair> book(m);

    for(int i = 0; i < m; i++) {
        cin >> book[i].first >> book[i].second;
    }
    sort(book.begin(), book.end());

    int index = 0;

    for(int i = 1; i <= n; i++) {
        while(index < m && book[index].first <= i) {
            list.push(book[index++].second);
        }
        while(!list.empty()) {
            if(list.top() >= i) {
                res++;
                list.pop();
                break;
            }
            else {
                list.pop();
            }
        }
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