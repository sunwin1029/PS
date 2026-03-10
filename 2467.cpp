#include <bits/stdc++.h>
using namespace std;

int arr[100100];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int left_index = 0;
    int right_index = n - 1;
    int res = INT_MAX;

    int res_left = 0;
    int res_right = n - 1;

    while(left_index < right_index) {
        int tmp = arr[left_index] + arr[right_index];
        if(abs(tmp) < res) {
            res = abs(tmp);
            res_left = left_index;
            res_right = right_index;
        }

        if(tmp < 0) {
            left_index++;
        }
        else if(tmp > 0) {
            right_index--;
        }
        else {
            break;
        }
    }

    cout << arr[res_left] << " " << arr[res_right] << "\n";

    return 0;
}