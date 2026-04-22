#include <bits/stdc++.h>
using namespace std;

void program() {
    string s;
    getline(cin, s);
    stringstream ss(s);

    string tmp;
    vector <string> word_list;

    while(ss >> tmp) {
        word_list.push_back(tmp);
    }

    for(int i = 0; i < word_list.size(); i++) {
        reverse(word_list[i].begin(), word_list[i].end());
    }

    for(int i = 0; i < word_list.size(); i++) {
        cout << word_list[i] << " ";
    }

    cout << "\n";
 }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while(t--) {
        program();
    }

    return 0;
}