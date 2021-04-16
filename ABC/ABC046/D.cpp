/**
 *	author:  reiya0104
 *	created: 05.04.2021 00:03:17
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;

int N;
string S;

vector<vector<int>> dp;

template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    cin >> S;
    N = (int)S.size();

    dp.resize(N + 2);
    for (int i = 0; i < dp.size(); ++i) dp.at(i).assign(i / 2 + 1, 0);
    dp.at(0).at(0) = 0;

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= i / 2; ++j) {
            // i回目
            // pを出さない(gをだす)
            if (S.at(i - 1) == 'p') { // まける
                dp.at(i + 1).at(j) = dp.at(i).at(j) - 1;
            } else { // あいこ
                dp.at(i + 1).at(j) = dp.at(i).at(j);
            }
            // p をだす
            if (j - 1 >= 0) {
                if (j <= (i - j)) {
                    // i文字目
                    if (S.at(i - 1) == 'p') { // あいこ
                        chmax(dp.at(i + 1).at(j), dp.at(i).at(j - 1));
                    } else { // 勝つ
                        chmax(dp.at(i + 1).at(j), dp.at(i).at(j - 1) + 1);
                    }
                }
            }
        }
    }

    // for (int i = 0; i < dp.size(); ++i) {
    //     cout << i << ":" << endl;
    //     for (int j = 0; j < dp.at(i).size(); ++j) {
    //         cout << "    " << j << ": " << dp.at(i).at(j) << endl;
    //     }
    //     cout << endl;
    // }

    int res = 0;
    for (int j = 0; j < (int)dp.at(N + 1).size(); ++j) {
        chmax(res, dp.at(N + 1).at(j));
    }
    cout << res << endl;
}
