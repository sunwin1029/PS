#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    deque <int> card;

    for(int i = 1; i <= n; i++) {
        card.push_back(i);
    }

    while(card.size() > 1) {
        int tmp = card.front();
        cout << tmp << " ";
        card.pop_front();
        tmp = card.front();
        card.pop_front();
        card.push_back(tmp);
    }

    cout << card.front();

    cout << "\n";

    return 0;
}