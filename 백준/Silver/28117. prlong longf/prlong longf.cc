#include <iostream>
#include <vector>
#include <string.h>

int dp[100];

int f(int n) {
    if(dp[n] > 0)
    return dp[n];
    else
    dp[n] = f(n - 1) + f(n - 2);
    return dp[n];
}


int main() {
    int n;
    char arr[100];
    dp[0] = 1;
    dp[1] = 1;
    
    int l_num = 0;
    int res = 1;
    
    std::cin >> n;
    std::cin >> arr;
    for(int i = 0; i < n; i++) {
        if(i + 3 < n && arr[i] == 'l' && arr[i + 1] == 'o' && arr[i + 2] == 'n' && arr[i + 3] == 'g')
        {
           l_num++;
           //std::cout << "check\n";
           i += 3;
           if(i >= n - 1) {
            res *= f(l_num);
            break;
           }
        }
        else {
            res *= f(l_num);
            l_num = 0;
        }
    }
    std::cout << res;
    return 0;
}