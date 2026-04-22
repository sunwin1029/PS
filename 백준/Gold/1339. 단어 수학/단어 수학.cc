#include <bits/stdc++.h>
using namespace std;

int n;
string arr[10];
// long long weight[26];
pair<char, long long> weight[26]; 
int num[100];

bool Compare(pair <char, long long> a, pair<char, long long> b) {
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i < 26; i++) {
        weight[i].first = i + 'A';
    }

    for(int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        arr[i] = tmp;

        int len = tmp.length();

        for(int j = 0; j < len; j++) {
            weight[tmp[j] - 'A'].second += pow(10, len - j - 1);
        }
    }

    sort(weight, weight + 26, Compare);

    for(int i = 0; i < 10; i++) {
        num[weight[i].first] = 9 - i; 
    }

    long long res = 0;

    for(int i = 0; i < n; i++) {
        string tmp = arr[i];
        int len = tmp.length();

        for(int j = 0; j < len; j++) {
            res += pow(10, len - j - 1) * num[tmp[j]];
        }
    }

    cout << res << "\n";

    return 0;
}