#include <bits/stdc++.h>
using namespace std;

int alphabet[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    cin >> s;

    for(int i = 0; i < s.length(); i++) {
        int index = s[i] - 'A';
        alphabet[index]++;
    }

    int odd_alphabet = 0;
    int loc_odd_alphabet = -1;
    for(int i = 0; i < 26; i++) {
        if(alphabet[i] % 2 != 0) {
            odd_alphabet++;
            loc_odd_alphabet = i;
        }
    }

    if(odd_alphabet > 1 || (odd_alphabet > 0 && s.length() % 2 == 0)) {
        cout << "I'm Sorry Hansoo\n";
        return 0;
    }

    string res(s.length(), '!');
    int current_res_char = 0;
    int alphabet_index = 0;
    int res_index = 0;

    if(s.length() % 2 != 0) {
        res[s.length() / 2] = 'A' + loc_odd_alphabet;
        alphabet[loc_odd_alphabet]--;
        current_res_char++;
    }

    while(current_res_char < s.length()) {
        if(alphabet[alphabet_index] == 0) {
            alphabet_index++;
            continue;
        }

        res[res_index] = 'A' + alphabet_index;
        res[s.length() - res_index - 1] = 'A' + alphabet_index;
        res_index++;
        current_res_char += 2;
        alphabet[alphabet_index] -= 2;
    }

    cout << res << "\n";


    return 0;
}