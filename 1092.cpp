#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    int res = 0;

    vector <int> crane;
    vector <int> box;


    cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        crane.push_back(tmp);
    }

    cin >> m;
    vector <bool> box_complete(m, false);
    for(int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        box.push_back(tmp);
    }

    sort(crane.begin(), crane.end(), greater<int>());
    sort(box.begin(), box.end(), greater<int>());

    if(box[0] > crane[0]) {
        cout << "-1\n";
        return 0;
    }

    int tmp_m = m;

    while(tmp_m > 0) {
        for(int i = 0; i < n; i++) {
            bool break_sign = false;
            for(int j = 0; j < m; j++) {
                if(crane[i] >= box[j] && !box_complete[j]) {
                    box_complete[j] = true;
                    tmp_m--;
                    break;
                } 
                if(j == m - 1) {
                    break_sign = true;
                }
            }
            if(break_sign) break;
        }
        res++;
    }

    cout << res << "\n";


    return 0;
}