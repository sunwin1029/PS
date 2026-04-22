#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
    stack <char> arr;
    string s;
    cin >> s;
    int bar = 0;
    int amt = 0;
    for(auto c : s) {
        if(c == '(') {
            arr.push('(');
            bar++;
        }
        if(c == ')') {
            if(arr.top() == '(') {
                arr.push(')');
                bar--;
                amt += bar;
                continue;
            }
            else {
                bar--;
                amt++;
            }
        }    
    }
    cout << amt;
    return 0;
}