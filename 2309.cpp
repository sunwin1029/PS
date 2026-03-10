#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector <int> arr(9);

    int sum = 0;

    for(int i = 0; i < 9; i++) {
        cin >> arr[i];
        sum += arr[i];
    }


    sort(arr.begin(), arr.end());

    for(int i = 0; i < 8; i++) {
        bool out = false;
        for(int j = 1; j < 9; j++) {
            int tmp = sum;

            tmp -= arr[i];
            tmp -= arr[j];

            if(tmp == 100) {
                arr[i] = -1;
                arr[j] = -1;
                out = true;
                break;
            }
        }
        if(out) break;
    }

    for(int i = 0; i < 9; i++) {
        if(arr[i] > 0) cout << arr[i] << "\n";
    }
    

    return 0;
}