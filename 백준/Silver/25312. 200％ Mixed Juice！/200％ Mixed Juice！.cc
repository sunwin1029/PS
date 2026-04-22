#include <bits/stdc++.h>
using namespace std;
bool compare(pair<int, int> a,pair<int, int> b) {
    return (double)a.second / a.first > (double)b.second / b.first;
}
long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, m;
    cin >> n >> m;
    pair <long long, long long> j[100100];
    for(int i = 0; i < n; i++) cin >> j[i].first >> j[i].second;
    sort(j, j + n, compare);
    /*
    cout << "*************\n";
    for(int i = 0; i < n; i++) {
        cout << j[i].first << " " << j[i].second << "\n";
    }
    */
    long long sum = 0;
    long long sum_sugar = 0;

    long long check;
    long long x;
    for(int i = 0; i < n; i++) {
        if(sum + j[i].first >= m) {
            x = m - sum;
            check = i;
            break;
        }
        sum += j[i].first;
        sum_sugar += j[i].second;
    }
    long long a, b;
    
    a = sum_sugar * j[check].first + x * j[check].second;
    b = j[check].first;
    //cout << a << "/" << b; 
    long long g = gcd(a, b);
    a /= g;
    b /= g;
    cout << a << "/" <<  b;
    return 0;
}