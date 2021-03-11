/**
 *	author:  reiya0104
 *	created: 09.03.2021 16:54:30
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    int D, N;
    cin >> D >> N;
    vector<int> DT(D + 1, 0);
    for (int i = 1; i <= D; i++) cin >> DT.at(i);
    vector<pair<int, int>> CT(N + 1);
    vector<int> C(N + 1, 0);
    CT.at(0).first = 0;
    CT.at(0).second = 0;
    for (int j = 1; j <= N; ++j)
        cin >> CT.at(j).first >> CT.at(j).second >> C.at(j);

    // DPデータ
    // dp:=(i-1)日目までに着た服の連続した日の派手さの絶対値の合計(なるべく大きくとる)
    // 添え字jはi-1日目に着た服の添え字jを表している
    // D日目まで着るのはdp.at(D+1)すなわちD+2個のデータが必要
    vector<vector<int>> dp(D + 2, vector<int>(N + 2, 0));

    // 初期値
    // 宣言時とDPループ内に組み込んであるので不要

    // DPループ
    for (int i = 2; i <= D; ++i) {
        for (int j = 1; j <= N; ++j) {
            // i日目に着る服を考える
            // すなわちdp.at(i + 1)を考える

            // その日の最高気温が服にとって適しているとき
            if (DT.at(i) >= CT.at(j).first && DT.at(i) <= CT.at(j).second) {
                // 前日に着ていた服の候補
                for (int k = 1; k <= N; ++k) {
                    // 前日が条件を満たしていれば
                    if (DT.at(i - 1) >= CT.at(k).first &&
                        DT.at(i - 1) <= CT.at(k).second) {
                        chmax(dp.at(i + 1).at(j),
                              dp.at(i).at(k) + abs(C.at(k) - C.at(j)));
                    }
                }
            }
        }
    }

    // 答え
    // D日目までの最大値より，dp.at(D + 1)を調べればいい
    int res = 0;
    for (int j = 1; j <= N; ++j) {
        chmax(res, dp.at(D + 1).at(j));
    }
    cout << res << endl;

    // Debug
    // for (int i = 0; i < dp.size(); ++i) {
    //     for (int j = 0; j < dp.at(i).size(); ++j) {
    //         if (dp.at(i).at(j) != 0) {
    //             cout << "dp.at(" << i << ").at(" << j
    //                  << ") = " << dp.at(i).at(j) << endl;
    //         }
    //     }
    // }
}
