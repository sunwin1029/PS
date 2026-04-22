#include <iostream>
#include <algorithm>

int value(int x) {
    if(x >= 0)
    return x;
    else
    return x * -1;
}

int main() {
    int n;
    std::cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
    std::cin >> arr[i];
    std::sort(arr, arr + n);
    int x = 0; // x = left
    int y = n - 1; // y = right
    int best_num_x = arr[x];
    int best_num_y = arr[y];
    int best_case = value(arr[x] + arr[y]);
    int current_case;
    while(1) {
        current_case = value(arr[x] + arr[y]);
        // std::cout << "x : " << x << " y : " << y << "\n"; 
        if(x == y)
        break;
        if(current_case >= value(arr[x + 1] + arr[y])) {
            x++;
            if(x == y)
            break;
            current_case = value(arr[x] + arr[y]);
            if(best_case >= current_case) {
                best_case = current_case;
                best_num_x = arr[x];
                best_num_y = arr[y];
                //std::cout << "new case x : " << best_num_x << "\n";
            }
            continue;
        }
        if(current_case >= value(arr[x] + arr[y - 1])) {
            y--;
            if(x == y)
            break;
            current_case = value(arr[x] + arr[y]);
            if(best_case >= current_case) {
                best_case = current_case;
                best_num_x = arr[x];
                best_num_y = arr[y];
                //std::cout << "new case y : " << best_num_y << "\n";
            }
            continue;
        }
        if(arr[x + 1] - arr[x] < arr[y] - arr[y - 1])
        x++;
        else
        y--;
        // std::cout << "x : " << x << " y : " << y << "\n"; 
    }
    
    std::cout << best_num_x << " " << best_num_y;
    delete[] arr;
    return 0;
}