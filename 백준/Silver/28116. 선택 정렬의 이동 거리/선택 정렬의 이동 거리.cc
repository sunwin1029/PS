#include <iostream>
#include <vector>


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::vector<int>arr;
    std::vector<int>arr_2;
    std::vector<int>check;
    int n;
    std::cin >> n;
    
    arr.reserve(n + 2);
    arr_2.reserve(n + 2);
    check.reserve(n + 2);
    
    int x;
    for(int i = 1; i <= n; i++) {
        std::cin >> x;
        arr[i] = x;
        arr_2[x] = i;
    }

    
    for(int i = 1; i <= n; i++) {
            int j = arr_2[i];
            check[i] += j - i;
            check[arr[i]] += j - i;
            arr_2[arr[i]] = j;
            arr_2[i] = i;
            arr[j] = arr[i];
            arr[i] = i;
            
    }
    
    for(int i = 1; i <= n; i++)
    std::cout << check[i] << " ";

    return 0;
}