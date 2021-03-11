/**
 *	author:  reiya0104
 *	created: 09.03.2021 16:05:58
 **/

#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001000;
const int MOD = 10000;

int main() {
    // 入力
    int N, K;
    cin >> N >> K;
    vector<int> data(N + 1, 0);
    for (int i = 0; i < K; ++i) {
        int A, B;
        cin >> A >> B;
        data.at(A) = B;
    }

    // DPデータ
    // dp:=(i-1)日目までのパスタの組み合わせの個数
    // j=1,2,3,k=1,2,3で，jはi-2日目, kはi-1日目に食べたパスタの種類を表す
    vector<vector<vector<int>>> dp(N + 2,
                                   vector<vector<int>>(4, vector<int>(4, 0)));

    // 初期値
    // 一日目と二日目に食べるものを決める
    // dp.at(3)をもとめる
    // data.at(1), data.at(2)が決まってるときと決まっていないときとで場合分け
    if (data.at(1) != 0) {
        if (data.at(2) != 0) {
            dp.at(3).at(data.at(1)).at(data.at(2)) = 1;
        } else {
            for (int k = 1; k <= 3; ++k) {
                dp.at(3).at(data.at(1)).at(k) = 1;
            }
        }
    } else {
        if (data.at(2) != 0) {
            for (int j = 1; j <= 3; ++j) {
                dp.at(3).at(j).at(data.at(2)) = 1;
            }
        } else {
            for (int j = 1; j <= 3; ++j) {
                for (int k = 1; k <= 3; ++k) {
                    dp.at(3).at(j).at(k) = 1;
                }
            }
        }
    }

    // DPループ
    for (int i = 3; i <= N; ++i) {
        for (int j = 1; j <= 3; ++j) {
            for (int k = 1; k <= 3; ++k) {
                // i日目に食べるものを考える

                // メニューに書いてあった
                if (data.at(i) != 0) {
                    // 3日連続ではない
                    if (j != k || k != data.at(i) || data.at(i) != j) {
                        dp.at(i + 1).at(k).at(data.at(i)) +=
                            dp.at(i).at(j).at(k);
                        dp.at(i + 1).at(k).at(data.at(i)) %= MOD;
                    }
                    continue;
                }

                // メニューにないとき
                for (int l = 1; l <= 3; ++l) {
                    // 3日連続ではない
                    if (j != k || k != l || l != j) {
                        dp.at(i + 1).at(k).at(l) += dp.at(i).at(j).at(k);
                        dp.at(i + 1).at(k).at(l) %= MOD;
                    }
                }
            }
        }
    }

    // 答え
    // N日食べたのはdp.at(N + 1)
    // すべてのj=1,2,3, k=1,2,3のものを足し合わせる
    int res = 0;
    for (int j = 1; j <= 3; ++j) {
        for (int k = 1; k <= 3; ++k) {
            res = (res + dp.at(N + 1).at(j).at(k)) % MOD;
        }
    }
    cout << res << endl;
}
