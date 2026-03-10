#include <bits/stdc++.h>
using namespace std;

void program(int n) {
    int tmp = 0;
    vector<int> container;

    for(int i = 1; i <= n / 2; i++) {
        if(n % i == 0) {
            tmp += i;
            container.push_back(i);
        }
    }

    if(tmp == n) {
        cout << n;
        for(int i = 0; i < container.size(); i++) {
            if(i == 0) cout << " = ";
            else cout << " + ";
            cout << container[i];
        }
        cout << "\n";
    } else {
        cout << n << " is NOT perfect.\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(true) {
        int n;
        cin >> n;

        if(n == -1)
            break;
        else {
            program(n);
        }
    }

    return 0;
}