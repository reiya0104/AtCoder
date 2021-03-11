#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001000;

const int MAX_N = 110;
const int MAX_V = 100100;

template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    // 入力
    int N;
    ll W;
    cin >> N >> W;
    vector<ll> w_v(N + 1, 0);
    vector<int> v_v(N + 1, 0);
    for (int i = 0; i < N; ++i) cin >> w_v.at(i) >> v_v.at(i);

    // DPデータ
    // dp.at(i).at(sum_v)
    // i-1番目までの品物の価値がsum_vとなるように選んだときの，重さの和の最小値
    vector<vector<ll>> dp(MAX_N, vector<ll>(MAX_V, 0));

    // DPループ
    for (int i = 0; i < N; ++i) {
        for (int sum_v = 0; sum_v < MAX_V,; ++sum_v) {
            // i番目を選ぶとき
            if (sum_v - v_v.at(i) >= 0) {
                chmin(dp.at(i + 1).at(sum_v), dp.at(i).at(sum_v - v_v.at(i)) + w_v.at(i));
            }

            // i番目を選ばないとき
            chmin(dp.at(i + 1).at(sum_v), dp.at(i).at(sum_v));
        }
    }

    // 答え
    int res = 0;
    for (int sum_v = 0; sum_v < MAX_V; ++sum_v) {
        if (dp.at(N + 1).at(sum_v) < W) res = sum_v;
    }
    cout << res << endl;

}
