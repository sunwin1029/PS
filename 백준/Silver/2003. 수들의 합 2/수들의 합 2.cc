#include <iostream>
using namespace std;
int main() {
    int n;
    int m;
    int cnt = 0;
    int arr[10001];
    int j;
    int sum = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    cin >> arr[i];
    
    for(int i = 0; i < n; i++) {
        j = i;
        sum = 0;
        while(sum < m) {
            sum += arr[j];
            j++;
            if(sum == m) cnt++;
        }
    }
    cout << cnt;
    

    return 0;
}