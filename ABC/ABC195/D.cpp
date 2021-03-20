/**
 *	author:  reiya0104
 *	created: 13.03.2021 21:28:51
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
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> W(N + 1);
    vector<int> V(N + 1);
    for (int i = 1; i <= N; ++i) cin >> W.at(i) >> V.at(i);
    vector<int> X(M + 1);
    for (int i = 1; i <= M; ++i) cin >> X.at(i);
    vector<pair<int, int>> query(Q + 1);
    for (int i = 1; i <= Q; ++i) cin >> query.at(i).first >> query.at(i).second;

    // デバッグ
    cout << "query=" << endl;
    for (int k = 1; k <= Q; ++k) {
        cout << query.at(k).first << " " << query.at(k).second << endl;
    }

    // クエリごとに行う
    for (int k = 1; k <= Q; ++k) {
        // DPデータ
        // dp.at(i).at(j)
        // i-1個までのしなものをjまでの箱に入れたときの価値の最大値
        vector<vector<int>> dp(N + 2, vector<int>(M + 1, 0));

        for (int i = 1; i <= N; ++i) {
            set<int> Set;
            for (int j = 1; j <= M; ++j) {
                // クエリ内にないなら
                if (!(query.at(k).first <= j && j <= query.at(k).second)) {
                    cout << "j = " << j << ", set = {";
                    for (auto itr = Set.begin(); itr != Set.end(); ++itr) {
                        cout << *itr << ", ";
                    }
                    cout << "}" << endl;

                    // i番目の品物を箱jに入れる
                    // 価値を最大化
                    if (W.at(i) <= X.at(j) && (Set.find(i) == Set.end())) {
                        if (chmax(dp.at(i + 1).at(j), V.at(i))) {
                            Set.insert(i);
                        }
                    }
                }

                // i番目の品物を箱jに入れない
                chmax(dp.at(i + 1).at(j), dp.at(i).at(j));

                cout << "dp.at(" << i + 1 << ").at(" << j  << ") = " << dp.at(i + 1).at(j) << endl;
            }
        }

        // 答え
        int res = 0;
        for (int j = 1; j <= M; ++j) {
            res += dp.at(N + 1).at(j);
        }
        cout << res << endl;
        cout << endl;
    }
}
