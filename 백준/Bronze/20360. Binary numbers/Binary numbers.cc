#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    queue <int> q;
    cin >> n;

    while(n > 0) {
        q.push(n % 2);
        n /= 2;
    }
    if(!q.size()) {
        cout << "0";
        return 0;
    } 
    for(int i = 0; q.size() > 0; i++) {
        if(q.front() == 1) cout << i << " ";
        q.pop();
    }
    return 0;

}