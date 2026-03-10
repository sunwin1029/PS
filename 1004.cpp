#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while(t--) {
        pair<int, int> start;
        pair<int, int> destination;
        int n;
        int res = 0;

        cin >> start.first >> start.second >> destination.first >>
            destination.second;
        cin >> n;

        while(n--) {
            pair<int, int> center;
            int radius;

            cin >> center.first >> center.second >> radius;

            bool start_in = false;
            bool destination_in = false;
            if(radius * radius >= pow(center.first - start.first, 2) +
                                      pow(center.second - start.second, 2)) {
                start_in = true;
            }
            if(radius * radius >= pow(center.first - destination.first, 2) +
                                      pow(center.second - destination.second, 2)) {
                destination_in = true;
            }

            if(start_in != destination_in) {
                res++;
            }
        }

        cout << res << "\n";
    }

    return 0;
}