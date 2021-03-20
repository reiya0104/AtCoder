/**
 *	author:  reiya0104
 *	created: 19.03.2021 18:18:05
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 100100100100;

int main() {
    // 入力
    int N, K;
    cin >> N >> K;
    assert(1 <= K && K <= N && N <= 15);
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A.at(i);

    // bit全探索
    ll res = INF;
    for (int bit = 0; bit < (1 << N); ++bit) {
        vector<int> a = A;
        vector<int> S;
        for (int i = 0; i < N; ++i) {
            if (bit & (1 << i)) {
                S.push_back(i);
            }
        }
        // cout << bit << ": {";
        // for (int i = 0; i < S.size(); ++i) {
        //     cout << S.at(i);
        //     if (i != S.size() - 1)
        //         cout << " ";
        //     else
        //         cout << "}" << endl;
        // }
        if (S.size() != K) continue;

        // SのサイズがK以上を調べると，自然にK色以上見える
        ll res0 = 0;
        // 左から順に見たときの最大値
        int M = a.at(0);
        // Sのインデックス
        int j = 0;
        for (int i = 0; i < N; ++i) {
            // cout << "j = " << j << endl;
            if (j == S.size()) break;

            if (i == S.at(j)) {
                // S内にあったら，建物を伸ばす
                // i = 0のときはインデックスのみ増やす
                // それ以外のときは，コストを足しMとjを更新する
                if (i != 0) {
                    int x = max((M + 1) - a.at(i), 0);
                    res0 += x;
                    a.at(i) += x;
                    M = a.at(i);
                }
                ++j;
            } else {
                // S内になかったら，Mを更新する
                M = max(M, a.at(i));
            }
        }

        if (res > res0) res = res0;
    }

    cout << res << endl;
}
