#include <bits/stdc++.h>
using namespace std;

bool arr[1010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    int index = 0;
    cin >> n >> k;

    while(true) {
        int num = 2;

        while(arr[num]) {
            num++;
        }

        for(int i = num; i <= n; i += num) {
            if(arr[i]) continue;
            index++;
            arr[i] = true;

            if(index >= k) {
                cout << i << "\n";
                return 0;
            }
        }

    }


    return 0;
}