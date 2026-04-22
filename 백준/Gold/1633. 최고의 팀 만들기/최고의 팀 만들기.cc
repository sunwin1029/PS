    #include <bits/stdc++.h>
    using namespace std;

    pair <int, int> player[1010]; // <white, black>
    int dp[1010][30][30];

    int f(int index, int black_left, int white_left) {
        if(index == 0) return 0;
        if(black_left < 0 || white_left < 0) return INT_MIN;
        if(black_left == 0 && white_left == 0) return 0;
        
        if(dp[index][black_left][white_left] > 0)
        return dp[index][black_left][white_left];

        int res = 0;
        res = max({f(index - 1, black_left - 1, white_left) + player[index].second
                    , f(index - 1, black_left, white_left - 1) + player[index].first
                    , f(index - 1, black_left, white_left)});
        dp[index][black_left][white_left] = res;
        return res;
    }

    int main() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int total_player = 1;
        int a, b;

        while(cin >> a >> b) {
            player[total_player].first = a;
            player[total_player].second = b;
            total_player++;
        }
        //cout << "input end\n";

        cout << f(total_player - 1, 15, 15) << "\n";


        return 0;
    }