#include <iostream>
#include <algorithm>
using namespace std;

int n, m, a;
int arr[100] = {0,};
int check[100] = {0,};
void f(int location, int a) {
    if(location == m) {
        for(int i = 0; i < m; i++)
        cout << arr[i] << " ";
        cout << "\n";
        return;
    }
    for(int i = a; i <= n; i++) {
        if(check[i] == 0) {
            arr[location] = i;
            check[i] = 1;
            a++;
            f(location + 1, a);
            check[i] = 0;
        } 
    }
    return;
}

int main() {

    cin >> n >> m;
    f(0, 1);
    return 0;
}