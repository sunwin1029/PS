#include <bits/stdc++.h>
using namespace std;

int Find(int x, vector <int> &arr) {
    if(arr[x] == x) return x;
    return arr[x] = Find(arr[x], arr);
}

bool Combine(int a, int b, vector <int> &arr) {
    a = Find(a, arr);
    b = Find(b, arr);

    if(a == b) return false;
    arr[b] = a;
    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int g, p;
    int res = 0;
    cin >> g >> p;

    vector <int> arr(g + 1);
    
    for(int i = 0; i <= g; i++) {
        arr[i] = i;
    }

    for(int i = 0; i < p; i++) {
        int tmp;
        cin >> tmp;

        if(Find(tmp, arr) == 0) break;
        else {
            res++;
            Combine(Find(tmp, arr) - 1, tmp, arr);
        }
    }

    cout << res << "\n";


    return 0;
}