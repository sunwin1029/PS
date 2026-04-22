#include <iostream>
#include <algorithm>
using namespace std;

int ballon[1000001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    long long m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> ballon[i];
    sort(ballon, ballon + n);
    long long left = 0;
    long long right = ballon[n - 1] * m;
    long long middle;
    long long res = 0;
    while(left <= right) {
        long long sum = 0;
        middle = (left + right) / 2;
        for(int i = 0; i < n; i++)
        sum += middle / ballon[i];
        if(sum >= m) {
            res = middle;
            right = middle - 1;
        }
        else if(sum < m)
            left = middle + 1;
    }
    cout << res;
    return 0;

}