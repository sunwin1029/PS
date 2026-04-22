#include <iostream>
#include <vector>
using namespace std;
vector <int> prime;
int check[1200001];
void find(int n) {
    int i = 0;
    while(1){
        if(prime[i] * prime[i] > n) break;
        while(n % prime[i] == 0) {
            cout << prime[i] << " ";
            n /= prime[i];
        }
        i++;
    }
    if(n != 1) cout << n;
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    for(int i = 2; i <= 1000001; i++) {
        if(check[i] == 0) {
            prime.push_back(i);
        }
        for(int j = i + i; j <= 1000001; j += i) 
        check[j] = 1;
    }

    int n, k;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> k;
        find(k);
    }
    return 0;

}