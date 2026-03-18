#include <bits/stdc++.h>
using namespace std;

int n, m;
vector <int> arr;

void backTracking(int index) {
    if(index > m) {
        for(int i = 1; i <= m; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 1; i <= n; i++) {
        arr[index] = i;
        backTracking(index + 1);
    }
        
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    arr.resize(m + 1);
    
    backTracking(1);

    return 0;
}