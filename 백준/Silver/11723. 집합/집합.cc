#include <iostream>
using namespace std;
int arr[21] = {};

void add(int x) {
    arr[x] = 1;
}
void remove(int x) {
    arr[x] =0;
}
void check(int x) {
    if(arr[x]) cout << "1\n";
    else cout << "0\n";
}
void toggle(int x) {
    if(arr[x]) arr[x] = 0;
    else arr[x] = 1;
}
void all() {
    for(int i = 1; i < 21; i++) arr[i] = 1;
}
void empty() {
    for(int i = 1; i < 21; i++) arr[i] = 0;
}
void execute() {
    string str;
    int x;
    cin >> str;
    if(str == "add") {
        cin >> x;
        add(x);
    }
    else if(str == "remove") {
        cin >> x;
        remove(x);
    }
    else if(str == "check") {
        cin >> x;
        check(x);
    }
    else if(str == "toggle") {
        cin >> x;
        toggle(x);
    }
    else if(str == "all") { all(); }
    else if(str == "empty") {empty();}

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) execute();
    return 0;
}