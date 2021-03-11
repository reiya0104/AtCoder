/**
 *	author:  reiya0104
 *	created: 08.03.2021 13:28:23
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    // 入力
    int N;
    ll D;
    cin >> N >> D;

    // DPデータ
    // dp.at(i).at(mul).at(k):=i番目までのサイコロの積mul(Dで合同)にkを掛けでDで割れたらtrue
    vector<vector<double>> dp(N + 1, vector<double>(D, 0));

    for (int i = 1; i <= 6; ++i) {
        dp.at(0).at(i % D) += 1 / 6.0;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < D; ++j) {
            for (int k = 1; k <= 6; ++k) {
                dp.at(i + 1).at((j * k) % D) += dp.at(i).at(j) / 6.0;
            }
        }
    }

    double res = dp.at(N - 1).at(0);
    // for (int i = 0; i < N; ++i) {
    //     res /= 6.0;
    // }

    // for (int i = 0; i < N; ++i) {
    //     for (int mul = 0; mul < D; ++mul) {
    //         cout << "dp.(" << i << ", " << mul << ") = " << dp.at(i).at(mul)
    //              << endl;
    //     }
    //     cout << endl;
    // }

    cout << res << endl;
}
