#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
namespace mp = boost::multiprecision;
using namespace std;

mp::cpp_int lucas(int i) {
    if (i == 0) {
        return 2;
    }
    else if (i == 1) {
        return 1;
    }
    else if (i >= 2) {
        mp::cpp_dec_float_100 x = 5.0f;
        mp::cpp_dec_float_100 s = (1 + mp::sqrt(x)) / 2;
        mp::cpp_dec_float_100 t = (1 - mp::sqrt(x)) / 2;
        return static_cast<mp::cpp_int>(mp::round(mp::pow(s, i) + mp::pow(t, i)));
        // return lucas(i - 1) + lucas(i - 2);
    }
    return -1;
}

int main() {
    int N;
    cin >> N;
    cout << lucas(N) << endl;
}
