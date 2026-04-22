#include <iostream>
#include <algorithm>
using namespace std;
long long ab(long long a) {
    if(a > 0) return a;
    else return -a;
}
int main() {
    long long n, m;
    long long arr[1001][1001];
    long long distance = 0;
    cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
        cin >> arr[j][i]; 
    }
    
    for(int i = 0; i < n; i++) {
        sort(arr[i], arr[i] + m);
    }
    /*
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
        cout << arr[j][i] << " ";
        cout << "\n";
    }
    */
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            distance += ab(arr[i][j] - arr[i][m / 2]);
        }
    }
    cout << distance << "\n";
    
    for(int i = 0; i < n; i++) {
        if(m % 2 == 1)
        cout << arr[i][m / 2] << " ";
        else
        cout << (arr[i][m / 2] + arr[i][m / 2 - 1]) / 2 << " ";
    }

    return 0;
}