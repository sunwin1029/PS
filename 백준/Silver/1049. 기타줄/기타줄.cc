#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;


    int package_min = INT_MAX;
    int each_min = INT_MAX;
    int res = 0;

    for(int i = 0; i < m; i++) {
        int a, b;

        cin >> a >> b;

        package_min = min(package_min, a);
        each_min = min(each_min, b);
    }

    if(each_min * 6 <= package_min) {
        cout << n * each_min << "\n";
        return 0;
    }

    while(n >= 6) {
        n -= 6;
        res += package_min;
    }
    
    if(n * each_min >= package_min) {
        res += package_min;
    }
    else {
        res += n * each_min;
    }

    cout << res << "\n";



    return 0;
}