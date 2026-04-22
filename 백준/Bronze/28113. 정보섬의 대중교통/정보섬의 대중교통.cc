#include <iostream>

int main() {
    int n, a, b;
    std::cin >> n >> a >> b;
    if(n > b)
    std::cout << "Bus";
    else {
        if(a > b)
        std::cout << "Subway";
        else if(a < b)
        std::cout << "Bus";
        else
        std::cout << "Anything";
    }

    return 0;
}