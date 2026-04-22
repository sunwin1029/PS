#include <iostream>
using namespace std;
int arr[100001];
int get_gcd(int a, int b) {
    if(b > a) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    if(a % b == 0) return b;
    return get_gcd(b, a % b);
}
int get_lcm(int a, int b) {
    int gcd = get_gcd(a, b);
    return (a / gcd) * (b / gcd) * gcd;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i = 0; i < n - 2; i++) cin >> arr[i];
    
    int lcm = 1;
    for(int i = 0; i < n - 2; i++) lcm = get_lcm(arr[i], lcm);
    cout << lcm;
    return 0;
    

}