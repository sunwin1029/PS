#include <bits/stdc++.h>
using namespace std;
vector<string> v;
map<string, int> dic;
string str;
bool compare(string a, string b) {
    if(dic[a] == dic[b] && a.length() == b.length())
    return a < b;
    if(dic[a] == dic[b])
    return a.length() > b.length();
    return dic[a] > dic[b];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> str;
        if(str.length() < m) continue;
        if(dic.find(str) == dic.end()) {
            //dic.insert({str, 0});
            v.push_back(str);
        }
        dic[str]++;

    }
    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }
    return 0;
    
}