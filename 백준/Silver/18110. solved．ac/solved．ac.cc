// Online C++ compiler to run C++ program online
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int main() {
    int arr[500000];
    int n;
    double new_n;
    int x;
    double sum = 0;
    double res;
    cin >> n;
    
    if(n == 0) {
        cout << 0;
        return 0;
    }
    for(int i = 0; i < n; i++)
    cin >> arr[i];
    
    sort(arr, arr + n, compare);
    
    new_n = (double)n * 0.15;
    x = (int)(floor(new_n + 0.5));
    
    // 문제 없음
    
    for(int i = 0; i < x; i++) {
        arr[i] = 0;
        arr[n - 1 - i] = 0;
    }
    sort(arr, arr + n, compare);
    /*
    for(int i = 0; i < n; i++)
    cout << arr[i];
    */
    
    for(int i = 0; i < n - 2 * x; i++) 
    sum += arr[i];
    
    sum /= n - 2 * x;
    res = floor((double)sum+ 0.5);
    
    cout << res;
    return 0;
}