#include <iostream>

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    // std::cout << "a = " << a << std::endl;
    // std::cout << "b = " << b << std::endl;
    // std::cout << "c = " << c << std::endl;

    // std::cout << "a + b + c = " << a + b + c << std::endl;

    if (a + b == c || c + b == a || a + c == b) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }

}
