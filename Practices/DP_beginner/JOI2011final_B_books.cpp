/**
 *	author:  reiya0104
 *	created: 09.03.2021 18:40:52
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
    int N, K;
    cin >> N >> K;
    vector<pair<int, int>> data(N + 1);
    for (int i = 1; i <= N; ++i) {
        int B;
        cin >> data.at(i).first >> B;
        // ジャンルの番号を1下げて0..9にする
        data.at(i).second = B - 1;
    }

    // DPデータ
    // dp:=(i-1)個目までの本を選んだときの本の個数
    // kは
    // dp.at(i).at(j).at([10, [1, 2, 3, 4, 5, 6 ,7 ,8 ,9 ,10]])みたいなかんじ
    vector<vector<
        pair<int, tuple<int, int, int, int, int, int, int, int, int, int>>>>
        dp(K + 2, vector<pair<int, tuple<int, int, int, int, int, int, int, int,
                                         int, int>>>(N + 1));
    // DP初期化
    for (int i = 0; i <= K; ++i) {
        for (int j = 0; j <= N; ++j) {
            dp.at(i).at(j).first = 0;
            dp.at(i).at(j).second = make_tuple(0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        }
    }

    // DPループ
    for (int i = 1; i <= K; ++i) {
        for (int j = 0; j <= N; ++j) {
            // j番目の本を考える
            // j番目を買わない
            chmax(dp.at(i + 1).at(j).first, dp.at(i).at(j).first);
            dp.at(i + 1).at(j).second = dp.at(i).at(j).second;

            // j番目を買う
            // 場合分け
            if (data.at(j).second == 0) {
                chmax(dp.at(i + 1).at(j).first,
                      dp.at(i).at(j).first + data.at(j).first +
                          2 * get<0>(dp.at(i).at(j).second));
                get<0>(dp.at(i + 1).at(j).second)++;
            }
            if (data.at(j).second == 1) {
                chmax(dp.at(i + 1).at(j).first,
                      dp.at(i).at(j).first + data.at(j).first +
                          2 * get<1>(dp.at(i).at(j).second));
                get<1>(dp.at(i + 1).at(j).second)++;
            }
            if (data.at(j).second == 2) {
                chmax(dp.at(i + 1).at(j).first,
                      dp.at(i).at(j).first + data.at(j).first +
                          2 * get<2>(dp.at(i).at(j).second));
                get<2>(dp.at(i + 1).at(j).second)++;
            }
            if (data.at(j).second == 3) {
                chmax(dp.at(i + 1).at(j).first,
                      dp.at(i).at(j).first + data.at(j).first +
                          2 * get<3>(dp.at(i).at(j).second));
                get<3>(dp.at(i + 1).at(j).second)++;
            }
            if (data.at(j).second == 4) {
                chmax(dp.at(i + 1).at(j).first,
                      dp.at(i).at(j).first + data.at(j).first +
                          2 * get<4>(dp.at(i).at(j).second));
                get<4>(dp.at(i + 1).at(j).second)++;
            }
            if (data.at(j).second == 5) {
                chmax(dp.at(i + 1).at(j).first,
                      dp.at(i).at(j).first + data.at(j).first +
                          2 * get<5>(dp.at(i).at(j).second));
                get<5>(dp.at(i + 1).at(j).second)++;
            }
            if (data.at(j).second == 6) {
                chmax(dp.at(i + 1).at(j).first,
                      dp.at(i).at(j).first + data.at(j).first +
                          2 * get<6>(dp.at(i).at(j).second));
                get<6>(dp.at(i + 1).at(j).second)++;
            }
            if (data.at(j).second == 7) {
                chmax(dp.at(i + 1).at(j).first,
                      dp.at(i).at(j).first + data.at(j).first +
                          2 * get<7>(dp.at(i).at(j).second));
                get<7>(dp.at(i + 1).at(j).second)++;
            }
            if (data.at(j).second == 8) {
                chmax(dp.at(i + 1).at(j).first,
                      dp.at(i).at(j).first + data.at(j).first +
                          2 * get<8>(dp.at(i).at(j).second));
                get<8>(dp.at(i + 1).at(j).second)++;
            }
            if (data.at(j).second == 9) {
                chmax(dp.at(i + 1).at(j).first,
                      dp.at(i).at(j).first + data.at(j).first +
                          2 * get<9>(dp.at(i).at(j).second));
                get<9>(dp.at(i + 1).at(j).second)++;
            }
        }
    }

    // 答え
    cout << dp.at(K + 1).at(N).first << endl;

    cout << "data = " << endl;
    for (int j = 0; j <= N; ++j) {
        cout << j << ": " << data.at(j).first << ", " << data.at(j).second
             << endl;
    }

    for (int i = 0; i <= K + 1; ++i) {
        for (int j = 0; j <= N; ++j) {
            if (dp.at(i).at(j).first != 0) {
                cout << "(" << i << ", " << j << ") = " << dp.at(i).at(j).first;
                cout << ", (" << get<0>(dp.at(i).at(j).second) << ", "
                     << get<1>(dp.at(i).at(j).second) << ", "
                     << get<2>(dp.at(i).at(j).second) << ", "
                     << get<3>(dp.at(i).at(j).second) << ", "
                     << get<4>(dp.at(i).at(j).second) << ", "
                     << get<5>(dp.at(i).at(j).second) << ", "
                     << get<6>(dp.at(i).at(j).second) << ", "
                     << get<7>(dp.at(i).at(j).second) << ", "
                     << get<8>(dp.at(i).at(j).second) << ", "
                     << get<9>(dp.at(i).at(j).second) << ")" << endl;
            }
        }
    }
}
