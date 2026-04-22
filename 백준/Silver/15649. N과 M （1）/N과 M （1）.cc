#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[100] = {0,};
int check[100] = {0,};
void f(int location) {
    if(location == m) {
        for(int i = 0; i < m; i++)
        cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(check[i] == 0) {
            arr[location] = i;
            check[i] = 1;
            f(location + 1);
            check[i] = 0;
        } 
    }
    return;
}

int main() {

    cin >> n >> m;
    f(0);
    
    

    return 0;
}