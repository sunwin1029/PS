#include <bits/stdc++.h>
using namespace std;
int n, s;
int arr[20];
int cnt = 0;
void f(int x, int sum) {
    if(x == n) {
        if(sum == s) cnt++;
        return;
    }
    f(x + 1, sum);
    f(x + 1, sum + arr[x]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> arr[i];
    f(0, 0);
    if(s == 0) cnt--;
    cout << cnt;
    return 0;


}