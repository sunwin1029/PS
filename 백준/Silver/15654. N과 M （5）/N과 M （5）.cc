#include <bits/stdc++.h>
using namespace std;

int n, m;
vector <int> arr;

void f(int amt, vector <bool> &c, deque <int> &d) {
    if(amt == 0) {
        for(int i : d) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 0; i < n; i++) {
        if(c[i] == true) continue;
        // cout << arr[i] << " ";
        c[i] = true;
        d.push_back(arr[i]);
        f(amt - 1, c, d);
        d.pop_back();
        c[i] = false;
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector <bool> check (n, false);
    deque <int> d;

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end());

    f(m, check, d);



    return 0;
}