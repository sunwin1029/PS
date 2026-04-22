#include <iostream>
#include <vector>
using namespace std;

vector <int> v;
int check[8000008];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 2; i <= 8000001; i++) {
        if(check[i] == 0) {
            v.push_back(i);
        }
        for(int j = i + i; j <= 8000001; j += i) 
        check[j] = 1;

    }

    int n;
    cin >> n;
    cout << v[n - 1];
    return 0;
}