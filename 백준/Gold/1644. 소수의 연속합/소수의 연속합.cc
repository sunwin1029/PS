#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector <bool> isPrime(n + 10, true);
    
    for(int i = 2; i <= (int)sqrt(n) + 1; i++) {
        if(!isPrime[i]) continue;
        for(int j = 2; i * j <= n; j++) {
            isPrime[i * j] = false;
        }
    }

    vector <int> prime;

    for(int i = 2; i <= n; i++) {
        if(isPrime[i]) prime.push_back(i);
    }

    int primeNum = prime.size();

    // for(int i = 0; i < primeNum; i++) {
    //     cout << "** " << prime[i] << "\n";
    // }
    vector <int> sumPrime(n + 10, 0);

    for(int i = 0; i < primeNum; i++) {
        int p = 0;
        for(int j = i; j < primeNum; j++) {
            p += prime[j];
            if(p > n) break;
            sumPrime[p]++;
        }
    }

    cout << sumPrime[n] << "\n";

    

    return 0;
}