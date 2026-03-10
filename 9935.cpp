#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    string bomb;

    cin >> s;
    cin >> bomb;

    stack<char> store;
    stack<char> tmp;
    for(int i = 0; i < s.length(); i++) {
        store.push(s[i]);

        while(store.size() >= bomb.length() && store.top() == bomb[bomb.length() - 1]) {
            bool isBomb = true;
            for(int j = 0; j < bomb.length(); j++) {
                if(store.top() == bomb[bomb.length() - 1 - j]) {
                    tmp.push(store.top());
                    store.pop();
                } else {
                    while(!tmp.empty()) {
                        store.push(tmp.top());
                        tmp.pop();
                        isBomb = false;
                    }
                    break;
                }
            }
            if(!isBomb) break;
            while(!tmp.empty()) tmp.pop();
        }
    }

    if(store.empty())
        cout << "FRULA\n";
    else {
        string res;
        while(!store.empty()) {
            res += store.top();
            store.pop();
        }
        for(int i = res.length() - 1; i >= 0; i--) {
            cout << res[i];
        } 
        cout << "\n";
    }

    

        return 0;
}