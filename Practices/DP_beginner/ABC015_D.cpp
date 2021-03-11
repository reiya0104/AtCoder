/**
 *	author:  reiya0104
 *	created: 08.03.2021 19:43:21
 **/

#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001000;

template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    // 入力
    int W, N, K;
    cin >> W >> N >> K;
    vector<pair<int, int>> data(N);
    for (int i = 0; i < N; ++i) cin >> data.at(i).first >> data.at(i).second;

    // DPデータ
    // dp.at(i).at(j).at(k):=(i-1)枚目までのスクリーンショットをとったときにj枚で幅kとっていたときにおける重要度
    vector<vector<vector<int>>> dp(
        N + 1, vector<vector<int>>(K + 1, vector<int>(W + 1, 0)));

    // 初期化
    // 何もしない

    // DPループ
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= K; ++j) {
            for (int k = 0; k <= W; ++k) {
                // i番目を選ばないとき
                chmax(dp.at(i + 1).at(j).at(k), dp.at(i).at(j).at(k));

                // i番目を選ぶとき
                if (k - data.at(i).first >= 0 && j < K) {
                    chmax(dp.at(i + 1).at(j + 1).at(k),
                          dp.at(i).at(j).at(k - data.at(i).first) +
                              data.at(i).second);
                }
            }
        }
    }

    // 答え
    int res = -INF;
    for (int k = 0; k <= W; ++k) {
        chmax(res, dp.at(N).at(K).at(k));
    }
    cout << res << endl;
}
