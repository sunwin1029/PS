#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    stack <int> s;

    cin >> n;

    int* arr = new int[n];

    for(int i = 0; i < n; i++)
    cin >> arr[i];

    for(int i = 0; i < n; i++) {
        /*
        if(s.size() == 0){}
            s.push(i);
            continue;
        } */
        while(s.size() != 0 && arr[s.top()] < arr[i]) {
            arr[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
        // 7 2 9 8 7
    }
    while(s.size() != 0) {
        arr[s.top()] = -1;
        s.pop();
    }
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    delete []arr;
    return 0;
    
}