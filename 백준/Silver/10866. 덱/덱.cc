#include <iostream>
#include <string.h>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    deque <int> d;
    char arr[20];
    int n;
    int x;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr;
        if(strcmp(arr, "push_front") == 0) {
            cin >> x;
            d.push_front(x);
        }
        else if(strcmp(arr, "push_back") == 0) {
            cin >> x;
            d.push_back(x);
        }
        else if(strcmp(arr, "pop_front") == 0) {
            if(d.size() < 1) cout << "-1\n";
            else {
                cout << d.front() << "\n";
                d.pop_front();
            }
        }
        else if(strcmp(arr, "pop_back") == 0) {
            if(d.size() < 1) cout << "-1\n";
            else {
                cout << d.back() << "\n";
                d.pop_back();
            }
        }
        else if(strcmp(arr, "size") == 0) cout << d.size() << "\n";
        
        else if(strcmp(arr, "empty") == 0) cout << d.empty() << "\n";
        
        else if(strcmp(arr, "front") == 0) {
            if(d.size() < 1) cout << "-1\n";
            else cout << d.front() << "\n";
        }
        else if(strcmp(arr, "back") == 0) {
            if(d.size() < 1) cout << "-1\n";
            else cout << d.back() << "\n";
        }
    }

    return 0;
}