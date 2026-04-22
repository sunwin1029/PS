#include <iostream>
using namespace std;

int dp[1000010];
string str[1000010];
int min_3(int a, int b, int c) {
    int min = 0;
    if(a <= b && a <= c) {
        min = 1;
    }
    else if(b <= a && b <= c) {
        min = 2;
    }
    else if(c <= a && c <= b) {
        min = 3;
    }
    return min;
}
int f(int num) {
    if(num == 1) {
        str[1] = "1";
        return 0;
    }
    if(dp[num] > 0)
    return dp[num];
    if(num % 3 != 0 && num % 2 != 0) {
        dp[num] = f(num - 1) + 1;
        str[num] = to_string(num) + " " + str[num - 1];
        return dp[num];
    }
    if(num % 3 == 0 && num % 2 != 0) {
        if(f(num / 3) < f(num - 1)) {
            dp[num] = f(num / 3) + 1;
            str[num] = to_string(num) + " " + str[num / 3];
        }
        else {
            dp[num] = f(num - 1) + 1;
            str[num] = to_string(num) + " " + str[num - 1];
        }
        return dp[num];
    }
    if(num % 3 != 0 && num % 2 == 0) {
        if(f(num / 2) < f(num - 1)) {
            dp[num] = f(num / 2) + 1;
            str[num] = to_string(num) + " " + str[num / 2];
        }
        else {
            dp[num] = f(num - 1) + 1;
            str[num] = to_string(num) + " " + str[num - 1];
        }
        return dp[num];
    }
    if(num % 3 == 0 && num % 2 == 0) {
        if(min_3(f(num / 3), f(num / 2), f(num - 1)) == 1) {
            dp[num] = f(num / 3) + 1;
            str[num] = to_string(num) + " " + str[num / 3];
        }
        else if(min_3(f(num / 3), f(num / 2), f(num - 1)) == 2) {
            dp[num] = f(num / 2) + 1;
            str[num] = to_string(num) + " " + str[num / 2];
        }
        else {
            dp[num] = f(num - 1) + 1;
            str[num] = to_string(num) + " " + str[num - 1];
        }
        return dp[num];
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int n;
    cin >> n;
    cout << f(n) << "\n";
    cout << str[n];
    cout << '!';
    return 0;

}