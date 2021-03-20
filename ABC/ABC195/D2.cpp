/**
 *	author:  reiya0104
 *	created: 14.03.2021 15:01:08
 **/

#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001000;

int main() {
    // 入力
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<pair<int, int>> WV(N);
    // 価値を第一要素にしておく
    for (int i = 0; i < N; ++i) cin >> WV.at(i).second >> WV.at(i).first;
    // 降順ソート
    sort(WV.begin(), WV.end(), greater<pair<int, int>>{});
    // W, Vの順番にもどす
    for (int i = 0; i < N; ++i) swap(WV.at(i).second, WV.at(i).first);

    vector<int> X(M);
    for (int i = 0; i < M; ++i) cin >> X.at(i);

    vector<pair<int, int>> LR(Q);
    for (int i = 0; i < Q; ++i) {
        int L, R;
        cin >> L >> R;
        LR.at(i) = make_pair(L - 1, R - 1);
    }

    for (int i = 0; i < Q; ++i) {
        vector<int> res_q(M, 0);
        for (int j = 0; j < N; ++j) {
            pair<int, int> index = make_pair(-1, INF);
            for (int k = 0; k < M; ++k) {
                if (k < LR.at(i).first || k > LR.at(i).second) {
                    if (res_q.at(k) == 0) {
                        if (WV.at(j).first <= X.at(k)) {
                            if (X.at(k) < index.second) {
                                index = make_pair(k, X.at(k));
                            }
                        }
                    }
                }
            }
            if (index.first != -1) {
                res_q.at(index.first) = WV.at(j).second;
            }
        }

        // 答え
        int res = 0;
        for (int j = 0; j < M; ++j) {
            res += res_q.at(j);
        }
        cout << res << endl;
    }
}
