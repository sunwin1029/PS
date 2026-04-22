#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    string s;

    cin >> n >> k >> s;

    stack <int> st;

    for(int i = 0; i < n; i++) {
        int num = s[i] - '0';

        while(!st.empty() && k > 0 && st.top() < num) {
            k--;
            st.pop();
        }
        st.push(num);
    }

    while(k > 0) {
        st.pop();
        k--;
    }

    deque <int> res;

    while(!st.empty()) {
        res.push_front(st.top());
        st.pop();
    }

    while(!res.empty()) {
        cout << res.front();
        res.pop_front();
    }

    cout << "\n";


    return 0;
}