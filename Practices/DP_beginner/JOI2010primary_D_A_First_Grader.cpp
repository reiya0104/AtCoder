/**
 *	author:  reiya0104
 *	created: 09.03.2021 15:19:57
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001000;

int main() {
    // 入力
    int N;
    cin >> N;
    vector<int> x(N);
    for (int i = 0; i < N; ++i) cin >> x.at(i);

    // DPデータ
    // dp:=i-1番目までの数字を計算して値がjとなるような組み合わせの数
    vector<vector<ll>> dp(N + 1, vector<ll>(21, 0));

    // 初期化
    dp.at(1).at(x.at(0)) = 1;

    // DPループ
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j <= 20; ++j) {
            // i番目では+の演算をする
            if (j - x.at(i) >= 0) {
                dp.at(i + 1).at(j) += dp.at(i).at(j - x.at(i));
            }

            // i番目では-の演算をする
            if (j + x.at(i) <= 20) {
                dp.at(i + 1).at(j) += dp.at(i).at(j + x.at(i));
            }
        }
    }

    // 答え
    cout << dp.at(N - 1).at(x.at(N - 1)) << endl;
}
