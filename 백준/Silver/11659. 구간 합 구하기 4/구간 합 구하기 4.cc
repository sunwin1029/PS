// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    int arr_num[100010] = {0,};
    long long sum_num[100010] = {0,};
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) cin >> arr_num[i];
    
    for(int i = 1; i <= n; i++) {
        sum_num[i] = sum_num[i - 1] + arr_num[i];
    }
    
    int i, j;
    for(int num = 1; num <= m; num++) {
        cin >> i >> j;
        cout << sum_num[j] - sum_num[i - 1] << "\n";
    }
    
    return 0;
}