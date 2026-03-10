#include <bits/stdc++.h>
using namespace std;

bool Compare(pair <int, int> &a, pair<int, int> &b) {
    return a.second > b.second;
}

int Find(vector <int> &arr, int index) {
    if(arr[index] == index) return index;
    else return arr[index] = Find(arr, arr[index]);
}

bool Combine(vector <int> &arr, int a, int b) {
    a = Find(arr, a);
    b = Find(arr, b);

    if(a == b) return false;
 
    arr[a] = b;
    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    long long res = 0;


    vector <pair <int, int>> homeWork(n);
    vector <int> usedSecond(n + 1);
    vector <bool> used(n + 1, false);

    for(int i = 0; i < n + 1; i++) {
        usedSecond[i] = i;
    }

    for(int i = 0; i < n; i++) {
        cin >> homeWork[i].first >> homeWork[i].second;
    }

    sort(homeWork.begin(), homeWork.end(), Compare);

    for(int i = 0; i < n; i++) {
        int tmp = Find(usedSecond, homeWork[i].first);
        if(tmp <= 0) continue;
        else {
            res += homeWork[i].second;
            Combine(usedSecond, tmp, tmp - 1);
        }
    }

    cout << res << "\n";

    return 0;
}