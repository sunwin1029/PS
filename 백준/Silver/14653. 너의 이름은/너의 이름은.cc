#include <iostream>

using namespace std;


int n, k, q;
int numNotRead;
char name;
int people[30][30];
int tmp_q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> q;
    //cout << "check\n";
    for(int i = 0; i < k; i++) {
        cin >> numNotRead >> name;
        name = (int)name - 65;
        for(int i = 0; i <= numNotRead; i++){
            people[i][name]++;
        }   
        if(i + 1 == q) {
            tmp_q = numNotRead;   
            if(numNotRead == 0) {
                cout << -1;
                return 0;
            }
        }
    }

    for(int i = 1; i < n; i++) {
        if(people[tmp_q][i] == 0) cout << (char)(i + 65) << " ";
    }


    return 0;

}