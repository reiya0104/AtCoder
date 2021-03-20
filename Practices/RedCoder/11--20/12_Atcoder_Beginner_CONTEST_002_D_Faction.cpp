/**
 *	author:  reiya0104
 *	created: 18.03.2021 19:10:58
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;

int main() {
    // 入力
    int N, M;
    cin >> N >> M;
    assert(1 <= N && N <= 12 && 0 <= M && M <= 66);
    vector<pii> xy(M);
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        xy.at(i) = make_pair(x - 1, y - 1);
    }
    // ソート
    sort(xy.begin(), xy.end());

    // bit全探索(2^12 * 66 = 270336 < 3*10^5)
    int res = 0;
    for (int bit = 0; bit < (1 << N); ++bit) {
        vector<int> S;
        for (int i = 0; i < N; ++i) {
            if (bit & (1 << i)) S.push_back(i);
        }
        if (S.size() <= res) continue;

        bool exist = true;
        for (int i = 0; i < S.size() - 1; ++i) {
            for (int j = i + 1; j < S.size(); ++j) {
                pair<int, int> key = make_pair(S.at(i), S.at(j));
                auto itr = lower_bound(xy.begin(), xy.end(), key);
                if (itr == xy.end() || *itr != key) {
                    exist = false;
                    break;
                }
            }
        }

        if (exist && res < S.size()) res = S.size();
    }

    // 答え
    cout << res << endl;
}
