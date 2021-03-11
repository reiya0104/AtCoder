#include <iostream>
#include <vector>

int main() {
    std::vector<int> A(2, 3);
    for (auto v: A) {
        std::cout << v << std::endl;
    }
    int B[2];
    B[0] = 1;
    B[1] = 2;
    for (auto v: B) {
        std::cout << v << std::endl;
    }
    std::cout << A[0] << std::endl; // OK
    std::cout << B[0] << std::endl; // OK
    std::cout << A.at(0) << std::endl; // OK
    std::cout << B.at(0) << std::endl; // OUT
}
