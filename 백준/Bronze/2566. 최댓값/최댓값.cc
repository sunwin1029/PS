#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[10][10];
    pair <int, int> res;
    int max_val = -1;

    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            int tmp;
            cin >> tmp;

            if(tmp > max_val) {
                max_val = tmp;
                res.first = i + 1;
                res.second = j + 1;
            }
        }
    }

    cout << max_val << "\n" <<res.first << " " << res.second << "\n";

    return 0;
}