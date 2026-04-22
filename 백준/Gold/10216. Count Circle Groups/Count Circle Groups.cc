#include <bits/stdc++.h>
using namespace std;

int find(int x, vector <int> &parent) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x], parent);
}

bool combine(int a, int b, vector<int> &parent) {
    a = find(a, parent);
    b = find(b, parent);
    if(a == b) return false;
    parent[b] = a;
    return true;
}

bool is_group(tuple <int, int, int> a, tuple <int, int, int> b) {
    if(pow((get<0>(b) - get<0>(a)), 2) + pow((get<1>(b) - get<1>(a)), 2) <= pow((get<2>(b) + get<2>(a)), 2)) {
        return true;
    }
    return false;
}


void program() {
    int n;

    cin >> n;
    int res = n;

    vector <tuple <int, int, int>> circle(n);
    vector <int> parent(n);

    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for(int i = 0; i < n; i++) {
        cin >> get<0>(circle[i]) >> get<1>(circle[i]) >> get<2>(circle[i]);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;

            if(is_group(circle[i], circle[j])) {
                // cout << "Check!\n";
                if(combine(i, j, parent)) {
                    res--;
                }
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
    
    while(t--) {
        program();
    }

    return 0;
}