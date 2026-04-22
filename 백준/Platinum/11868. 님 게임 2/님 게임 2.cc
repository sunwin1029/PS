#include <bits/stdc++.h>
using namespace std;

int arr[110];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int game_cnt;
    cin >> game_cnt;

    for(int i = 0; i < game_cnt; i++) {
        cin >> arr[i];
    }

    int res = arr[0];

    for(int i = 1; i < game_cnt; i++) {
        res ^= arr[i];
    }

    if(res) {
        cout << "koosaga\n";
    }
    else {
        cout << "cubelover\n";
    }

    return 0;
}