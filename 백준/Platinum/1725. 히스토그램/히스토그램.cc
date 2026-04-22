#include <iostream>
#include <stack>
using namespace std;

int bigger(long long a, long long b) {
    return a > b ? a : b;
}

int arr[100010];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    long long res = 0;
    stack <int> stack;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];

    stack.push(0);

    for(int i = 1; i <= n + 1; i++) {
        while(!stack.empty() && arr[stack.top()] > arr[i]) {
            int tmp = stack.top();
            stack.pop();
            res = bigger(res, arr[tmp] * (i - stack.top() - 1));
        }
        stack.push(i);
    }
    cout << res;
    return 0;
}