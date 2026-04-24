#include <bits/stdc++.h>
using namespace std;

int n;
vector <string> arr;
map <string, int> m;
int maxLen = 0;
int maxA = 0;
int maxB = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    arr.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++) {
        string s = "";
        for(int j = 0; j < arr[i].length(); j++) {
            s += arr[i][j];

            if(m.count(s)) {
                if(s.length() > maxLen) {
                    maxA = m[s];
                    maxB = i;
                    maxLen = s.length();
                }
                else if(s.length() == maxLen) {
                    if(m[s] < maxA) {
                        maxA = m[s];
                        maxB = i;
                    }
                }
            }
            else {
                m[s] = i;
            }
        }
    }

    cout << arr[maxA] << "\n" << arr[maxB] << "\n";

    return 0;
}