#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    int arr_num[1001];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr_num[i];
    }
    sort(arr_num, arr_num + n);
    int max = 1;
    for(int i = 0; i < n; i++) {
        if(max < arr_num[i]) {
            cout << max;
            return 0;
        }
        max += arr_num[i];
    }
    cout << max;
    return 0;
}