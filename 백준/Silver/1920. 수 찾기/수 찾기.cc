#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];

int find_int(int n, int first, int last) {
    if (first > last) return 0;
    int middle = (first + last) / 2;
    if (arr[middle] == n) return 1;
    if (arr[middle] > n) return find_int(n, first, middle - 1);
    if (arr[middle] < n) return find_int(n, middle + 1, last);
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    int m, check;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> check;
        cout << find_int(check, 0, n - 1) << "\n";
    }

    return 0;
}