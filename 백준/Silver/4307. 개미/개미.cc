#include <iostream>
#include <algorithm>
using namespace std;
int smaller(int a, int b) {
    return a < b ? a : b;
}
int bigger(int a, int b) {
    return a > b ? a : b;
}
void f() {
    int ant_location[1000001];
    int l, n;
    cin >> l >> n;
    for(int i = 0; i < n; i++) cin >> ant_location[i];
    sort(ant_location, ant_location + n);
    int sest_time = 0;
    int lest_time = 0;
    for(int i = 0; i < n; i++) {
        int s_time = smaller(ant_location[i], l - ant_location[i]);
        int l_time = bigger(ant_location[i], l - ant_location[i]);
        sest_time = bigger(s_time, sest_time);
        lest_time = bigger(l_time, lest_time);
    }
    cout << sest_time << " " << lest_time << "\n";
    
    
}


int main() {
    int t;
    cin >> t;
    while(t--) f();
    return 0;
}