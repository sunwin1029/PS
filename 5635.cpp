#include <bits/stdc++.h>
#define person tuple<string, int, int, int>
using namespace std;

bool Compare(person& a, person& b) {
    if(get<3>(a) == get<3>(b)) {
        if(get<2>(a) == get<2>(b)) {
            return get<1>(a) < get<1>(b);
        }
        return get<2>(a) < get<2>(b);
    }
    return get<3>(a) < get<3>(b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector<person> people(n);

    for(int i = 0; i < n; i++) {
        int tmp;

        cin >> get<0>(people[i]);
        cin >> get<1>(people[i]);
        cin >> get<2>(people[i]);
        cin >> get<3>(people[i]);
    }

    sort(people.begin(), people.end(), Compare);

    cout << get<0>(people[n - 1]) << "\n" << get<0>(people[0]) << "\n";

    return 0;
}