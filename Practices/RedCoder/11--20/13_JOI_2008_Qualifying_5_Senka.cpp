/**
 *	author:  reiya0104
 *	created: 19.03.2021 17:27:53
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;

int main() {
    int R, C;
    cin >> R >> C;
    assert(1 <= R && R <= 10 && 1 <= C && C <= 10000);
    vector<vector<int>> Mass(R, vector<int>(C));
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j) cin >> Mass.at(i).at(j);

    // bit全探索(2**10=1024)
    // 横のいくつかの行をひっくり返したとき，
    // 縦のひっくり返す列は決まり，そのときの最大値は一意に定まる．
    int res = 0;
    for (int bit = 0; bit < (1 << R); ++bit) {
        vector<vector<int>> mass = Mass;
        for (int i = 0; i < R; ++i) {
            if (bit & (1 << i)) {
                // 横をひっくり返す
                for (int j = 0; j < C; ++j) {
                    mass.at(i).at(j) = 1 - mass.at(i).at(j);
                }
            }
        }

        // 縦で裏側が焼けている個数を数える
        // 数え上げるのは表の数でも裏の数でもどちらでもいい
        // max(x, R - x)を返す
        int res0 = 0;
        for (int j = 0; j < C; ++j) {
            int res1 = 0;
            for (int i = 0; i < R; ++i) {
                if (mass.at(i).at(j) == 1) ++res1;
            }
            res0 += max(res1, R - res1);
        }

        if (res <= res0) res = res0;
    }

    cout << res << endl;
}
