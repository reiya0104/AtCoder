/**
 *	author:  reiya0104
 *	created: 06.03.2021 16:52:53
 **/

#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001000;
#define MAX 100010

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
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

// 入力
int N;
vector<int> p(110, 0);

// DPテーブル
vector<vector<int>> dp(110, vector<int>(MAX, -1));

int main() {
    // 入力
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> p.at(i);
    }

    // 初期化
    dp.at(0).at(0) = 0;

    // DPループ
    for (int i = 0; i < N; ++i) {
        for (int sum_p = 0; sum_p < MAX; ++sum_p) {
            dp.at(i + 1).at(sum_p) = dp.at(i).at(sum_p);
            if (sum_p - p.at(i) >= 0)
                dp.at(i + 1).at(sum_p) += dp.at(i).at(sum_p - p.at(i)) + 1;
        }
    }

    // 答え
    int rec = 0;
    for (int j = 0; j < MAX; ++j) {
        if (dp.at(N).at(j) >= 0) {
            cout << "sum_p = " << j << ": " << dp.at(N).at(j) << endl;
            ++rec;
        }
    }
    cout << rec << endl;

}
