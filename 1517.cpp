#include <bits/stdc++.h>
using namespace std;

vector <int> temp;
vector <int> arr;
long long res = 0;

void merge(int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            res += (mid - i + 1);
            temp[k++] = arr[j++];
        }
    }

        while(i <= mid) {
            temp[k++] = arr[i++];
        }
        while(j <= right) {
            temp[k++] = arr[j++];
        } 

    // 원본 정렬 옮기기
    for(int x = left; x <= right; x++) {
        arr[x] = temp[x];
    }

}

void mergeSort(int left, int right) {
    if(left >= right) return;

    int mid = (left + right) / 2;

    mergeSort(left, mid);
    mergeSort(mid + 1, right);

    merge(left, mid, right);
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    arr.resize(n + 1);
    temp.resize(n + 1);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(0, n - 1);

    cout << res << "\n";

    return 0;
}