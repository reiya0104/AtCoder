/**
 *	author:  reiya0104
 *	created: 08.03.2021 13:03:38
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1001001000;
#define MAX 10010

// 入力
int N;
vector<int> p(110);

// DPデータ
// dp.at(i).at(sum_p):=(i-1)番目までのコンテストを選んだときに点数がぴったりsum_p点となる組み合わせがあるならtrue
vector<vector<bool>> dp(110, vector<bool>(MAX, false));

int main() {
    // 入力
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> p.at(i);
    }
    // DP初期値
    dp.at(0).at(0) = true;

    // DPループ
    for (int i = 0; i < N; ++i) {
        for (int sum_p = 0; sum_p < MAX; ++sum_p) {
            // i番目のコンテストを選ばなかったとき
            dp.at(i + 1).at(sum_p) = dp.at(i).at(sum_p);

            // i番目のコンテストを選んだとき
            if (sum_p - p.at(i) >= 0) dp.at(i + 1).at(sum_p) = dp.at(i + 1).at(sum_p) | dp.at(i).at(sum_p - p.at(i));
        }
    }

    // 答え
    ll res = 0;
    for (int sum_p = 0; sum_p < MAX; ++sum_p) {
        if (dp.at(N).at(sum_p)) res += 1;
    }
    cout << res << endl;
}
