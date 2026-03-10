#include <bits/stdc++.h>
using namespace std;

int grundy[1010];

int mex(unordered_set <int> s) {
    int a = 0;
    while(true) {
        if(!s.count(a)) break;
        a++;
    }
    return a;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    grundy[0] = 0;
    grundy[1] = 0;
    grundy[2] = 1;

    for(int i = 3; i <= n; i++) {
        unordered_set <int> s;
        for(int j = 1; j <= i / 2; j++) {
            // 이웃한 두 변을 이은 경우
            if(j == 1) {
                s.insert(grundy[i - 2]);
            }
            // 그 외의 경우
            else {
                s.insert(grundy[j - 1] ^ grundy[i - j - 1]);
            }
        }

        grundy[i] = mex(s);
    }

    if(grundy[n]) {
        cout << "1\n";
    }
    else {
        cout << "2\n";
    }

    return 0;
}