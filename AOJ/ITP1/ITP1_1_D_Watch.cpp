#include <iostream>
#include <cstdio>

int main() {
    int S;
    std::cin >> S;
    int h, m, s;
    h = S / 3600;
    m = (S / 60) % 60;
    s = S % 60;
    printf("%d:%d:%d\n", h, m, s);
}
