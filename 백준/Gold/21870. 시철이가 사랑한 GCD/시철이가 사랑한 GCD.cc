#include <bits/stdc++.h>
using namespace std;
int arr[200200];

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int gcd_part(int start, int end) {
    int res = 0;
    for(int i = start; i <= end; i++) {
        res = gcd(res, arr[i]);
    }   
    return res;
}
int divide(int start, int end) {
    if(start == end) return arr[start];
    int mid = (start + end - 1) / 2;

    int left = gcd_part(start, mid) + divide(mid + 1, end);
    int right = gcd_part(mid + 1, end) + divide(start, mid);
    return max(left, right);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++) cin >> arr[i];

    cout << divide(0, n - 1);

    return 0;
}