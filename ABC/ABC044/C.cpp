/**
 *	author:  reiya0104
 *	created: 08.03.2021 11:28:21
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001000;

// 入力
int N, A;
vector<int> x(60);

// DPデータ
// dp.at(i).at(j).at(sum_x):=i-1番目までの数字をj個足したらぴったりsum_xとなるような個数
vector<vector<vector<ll>>> dp(60, vector<vector<ll>>(60, vector<ll>(2600, 0)));

int main() {
    // 入力
    cin >> N >> A;
    for (int i = 0; i < N; ++i) cin >> x.at(i);

    // dp初期値
    dp.at(0).at(0).at(0) = 1;

    // dpループ
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 60; ++j) {
            for (int sum_x = 0; sum_x < 2600; ++sum_x) {
                dp.at(i + 1).at(j).at(sum_x) = dp.at(i).at(j).at(sum_x);
                if (sum_x - x.at(i) >= 0 && j > 0) {
                    dp.at(i + 1).at(j).at(sum_x) +=
                        dp.at(i).at(j - 1).at(sum_x - x.at(i));
                }
            }
        }
    }

    // 答え
    ll res = 0;
    for (int j = 1; j < 60; ++j) {
        for (int sum_x = 0; sum_x < 2600; ++sum_x) {
            if (A * j == sum_x) res += dp.at(N).at(j).at(sum_x);
        }
    }
    cout << res << endl;
}
