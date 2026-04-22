//
//  1000.cpp
//  firstProject
//
//  Created by sunwin on 1/2/25.
//

#include <iostream>
using namespace std;

const long long MOD = 1000000007;

int main() {
    
    long long n, k;
    cin >> n >> k;
    
    /*
     정점의 수(point) = 이전 간선의 수
     각 정점별 간선의 수(edgeNum) = (전 정점별 간선의 수 - 1) * 2
     총 간선의 수(total) = 1 + ... + 각 정점별 간선의 수(n) = n * (n - 1) / 2
     출력해야 할 것 = 현재 간선의 수!
     12
     */
    if(n == 3) {
        cout << 3;
        return 0;
    }
    if (k == 0) {
        cout << n % MOD;
        return 0;
    }
    
    long long edgeNum = n - 1;
    long long total;
    long long point = n * (n - 1) / 2;
    for(int i = 1; i < k; i++) {
        edgeNum = (edgeNum - 1) * 2 % MOD;
        total = (edgeNum * point % MOD) * 500000004 % MOD;
        point = total % MOD;
    }

    cout << point % MOD;
    
    return 0;
}


