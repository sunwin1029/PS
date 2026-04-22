#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector <int> arr(n);
    vector <int> origin(n);

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        origin[i] = tmp;
        arr[i] = tmp;
    }

    sort(arr.begin(), arr.end());

    map <int, int> m;

    for(int i = 0; i < n; i++) {
        if(m.count(arr[i])) continue;

        else {
            m[arr[i]] = m.size();
        }
    }

    for(int i = 0; i < n; i++) {
        cout << m[origin[i]] << " ";
    }
    cout << "\n";
    


    return 0;
}