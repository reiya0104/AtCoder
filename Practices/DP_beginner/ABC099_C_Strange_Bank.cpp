/**
 *	author:  reiya0104
 *	created: 06.03.2021 14:19:59
**/
#include <iostream>
#include <vector>
const int INF = 1001001000;

template <class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    // 入力
    int N;
    std::cin >> N;
    std::vector<int> dp(1001000, INF);
    dp.at(0) = 0;
    for (int i = 0; i <= N; ++i) {
        chmin(dp.at(i + 1), dp.at(i) + 1);
        for (int j = 6; i + j <= N; j *= 6) chmin(dp.at(i + j), dp.at(i) + 1);
        for (int j = 9; i + j <= N; j *= 9) chmin(dp.at(i + j), dp.at(i) + 1);
    }
    std::cout << dp.at(N) << std::endl;
}
