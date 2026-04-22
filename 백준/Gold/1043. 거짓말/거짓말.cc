#include <bits/stdc++.h>
using namespace std;

int n, m;
int know_amt;

bool is_know[55];
bool know_party[55];
vector <vector <int>> party;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> know_amt;

    for(int i = 0; i < know_amt; i++) {
        int tmp;
        cin >> tmp;

        is_know[tmp] = true;
    }

    for(int i = 0; i < m; i++) {
        int amt;
        cin >> amt;

        vector <int> arr;
        
        for(int j = 0; j < amt; j++) {
            int tmp;
            cin >> tmp;
            arr.push_back(tmp);
        }

        party.push_back(arr);
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            if(know_party[j]) continue;
            for(int k = 0; k < party[j].size(); k++) {
                if(is_know[party[j][k]]) {
                    for(int x = 0; x < party[j].size(); x++) {
                        is_know[party[j][x]] = true;
                    }
                    know_party[j] = true;
                    break;
                }
            }
        }
    }

    int res = 0;
    for(int i = 0; i < m; i++) {
        if(!know_party[i]) res++;
    }

    cout << res << "\n";
    return 0;
}