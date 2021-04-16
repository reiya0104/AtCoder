/**
 *	author:  reiya0104
 *	created: 24.03.2021 13:33:05
 **/

#include <bits/stdc++.h>

#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace std;
using boost::multiprecision::cpp_dec_float_100 = f100;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;

f100 P;

int main() {
    cin >> P;
    f100 one = 1.0f, two = 2.0f, three = 3.0f;
    f100 key = (three / (two * log(two))) * (log((two * log(two) * P) / three));
    f100 res;
    if (key > 0)
        res = (three / (two * log(two))) * (log((two * log(two) * P) / three) + one);
    else
        res = P;
    std::cout << std::setprecision(std::numeric_limits<decltype(P)>::digits10 + 1)
              << res << endl;
}
