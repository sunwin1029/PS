#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;

    cin >> a >> b;

    vector <vector <int>> arr(a, vector <int> (b, 0));

    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            int tmp;
            cin >> tmp;

            arr[i][j] += tmp;
        }
    }

    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            int tmp;
            cin >> tmp;

            arr[i][j] += tmp;
        }
    }

    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}