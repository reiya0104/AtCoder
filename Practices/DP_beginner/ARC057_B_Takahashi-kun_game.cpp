/**
 *	author:  reiya0104
 *	created: 11.03.2021 15:45:26
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001000;

const int MAX_N = 2100;
const ll MAX_K = 1000001000;

template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b && b < INF) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    // 入力
    int N;
    ll K;
    cin >> N >> K;
    // i(>=1)日目のゲームの回数
    vector<int> a_v(MAX_N, 0);
    // i(>=1)日目までのゲームの回数の合計
    vector<int> s_v(MAX_N, 0);
    for (int i = 1; i <= N; ++i) {
        cin >> a_v.at(i);
        s_v.at(i) = s_v.at(i - 1) + a_v.at(i);
    }

    // DPデータ
    // dp.at(i).at(j)
    // i-1日目までの高橋くんの機嫌がよかった日の合計がぴったりj日であったときのゲームに勝った回数の合計
    // firstは一番小さい勝利数，secondはfirstに分岐しているときの最大の勝利数とする
    vector<vector<pair<ll, ll>>> dp(
        MAX_N, vector<pair<ll, ll>>(MAX_N, make_pair(INF, -INF)));
    dp.at(1).at(0) = make_pair(0, 0);
    dp.at(2).at(1) = make_pair(1, a_v.at(1));

    // DPループ
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < MAX_N; ++j) {
            // cout << "(" << i << ", " << j << ")" << endl;
            // i日目に機嫌がよかった
            // dp.at(i).at(j - 1)がi-1日目までにゲームに勝った回数になる
            // dp.at(i).at(j - 1) * s_v.at(i) <
            // dp.at(i + 1).at(j) * s_v.at(i - 1)
            // が成り立つ (dp.at(i).at(j - 1) * s_v.at(i) / s_v.at(i - 1)) <
            // dp.at(i + 1).at(j) <= dp.at(i).at(j - 1) + a_v.at(i) となる
            // この値がなるべく小さくなるのは，
            // dp.at(i + 1).at(j).first =
            // ceil(dp.at(i).at(j - 1).first * s_v.at(i) / s_v.at(i -
            // 1))であればいい 最大となるのは， dp.at(i + 1).at(j).second =
            // dp.at(i).at(j - 1).second + a_v.at(i) である．
            if (i - 1 >= 1 && j - 1 >= 0) {
                if ((dp.at(i).at(j - 1).first * s_v.at(i)) / s_v.at(i - 1) +
                        1 <=
                    dp.at(i).at(j - 1).first + a_v.at(i)) {
                    chmin(
                        dp.at(i + 1).at(j).first,
                        (dp.at(i).at(j - 1).first * s_v.at(i)) / s_v.at(i - 1) +
                            1);
                    chmax(dp.at(i + 1).at(j).second,
                          dp.at(i).at(j - 1).first + a_v.at(i));
                }

            }

            // i日目に機嫌がよくなかった
            // dp.at(i).at(j)がi-1日目までにゲームに勝った回数になる
            // dp.at(i).at(j) * s_v.at(i) >= dp.at(i + 1).at(j) * s_v.at(i - 1)
            // が成り立つ
            // dp.at(i + 1).at(j) <=
            // min(dp.at(i).at(j) + a_v.at(i),
            // dp.at(i).at(j) * s_v.at(i) / s_v.at(i - 1)) となる
            // この値がなるべく小さくなるのは，i日目に一度も勝たないことである
            // 最大となるのは，dp.at(i + 1).at(j) =
            // min(dp.at(i).at(j) + a_v.at(i),
            // dp.at(i).at(j) * s_v.at(i) / s_v.at(i - 1))
            // である．
            chmin(dp.at(i + 1).at(j).first, dp.at(i).at(j).first);
            if (i - 1 >= 1) {
                chmax(dp.at(i + 1).at(j).second,
                      min(dp.at(i).at(j).second + a_v.at(i),
                          dp.at(i).at(j).second * s_v.at(i) / s_v.at(i - 1)));
            } else {
                chmax(dp.at(i + 1).at(j).second,
                      dp.at(i).at(j).second + a_v.at(i));
            }

            // if (dp.at(i + 1).at(j) != 0 && dp.at(i + 1).at(j) != INF) {
            // if (dp.at(i + 1).at(j).first != INF &&
            //     dp.at(i + 1).at(j).second != -INF) {
            //     cout << "dp.at(" << i + 1 << ").at(" << j << ") = ("
            //          << dp.at(i + 1).at(j).first << ", "
            //          << dp.at(i + 1).at(j).second << ")" << endl;
            // }
        }
    }

    // 答え
    int res = 0;
    for (int j = 0; j < MAX_N; ++j) {
        if (dp.at(N + 1).at(j).first <= K && dp.at(N + 1).at(j).second >= K)
            res = j;
    }
    cout << res << endl;
}
