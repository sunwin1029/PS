#include <iostream>
using namespace std;
int res;
void z(long long len, int a, int b) {
    if(len == 1)  return;
    
    if(a < len / 2 && b < len / 2) { // a가 4등분중 2사분면 위치
        z(len / 2, a, b);
    }
    else if(a >= len / 2 && b < len / 2) { // a가 4등분중 1사분면 위치
        res += len * len / 4;
        z(len / 2, a - len / 2, b);
    }
    else if(a < len / 2 && b >= len / 2) { // a가 4등분중 3사분면 위치
        res += len * len / 2;
        z(len / 2, a, b - len / 2);
    }
    else if(a >= len / 2 && b >= len / 2) { // a가 4등분중 4사분면 위치
        res += len * len * 3 / 4;
        z(len / 2, a - len / 2, b - len / 2);
    }

}
int main() {
    res = 0;
    int n, r, c;
    long long new_n = 1;
    cin >> n >> r >> c;
    for(int i = 0; i < n; i++) new_n *= 2;
    z(new_n, c, r);
    // cout << new_n << "\n";
    cout << res;
    return 0;
} 