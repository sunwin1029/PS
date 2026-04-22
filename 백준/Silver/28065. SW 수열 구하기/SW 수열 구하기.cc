#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n / 2; i++) {
        cout << 1 + i << " ";
        if(1 + i >= n - i) break;
        cout << n - i << " ";
    }
    if(n % 2 != 0) {
        cout << n / 2 + 1; 
    }
    
    return 0;
}