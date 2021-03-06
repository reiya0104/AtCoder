/**
 *	author:  reiya0104
 *	created: 06.03.2021 12:20:58
 **/

#include <bits/stdc++.h>
using namespace std;
#define MAX 100100
const int INF = 1001001000;
const int MOD = 1000000007;

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
int M;
// OKなら1, NGなら0
vector<bool> A(MAX, 1);

// DP
// dp[i]はi段目までの登ることができる通り数を表すとする
int dp[MAX];

int main() {
    // 入力
    int N;
    cin >> N;
    int M;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        int a;
        cin >> a;
        A.at(a) = 0;
    }
    // 初期化
    for (int i = 0; i < MAX; ++i) dp[i] = 0;

    // 初期解
    // 0番目の階段まで登ることができるのは0通り?
    dp[0] = 1;

    // ループ(MODで考えることを忘れない)
    for (int i = 1; i <= N; ++i) {
        if (A.at(i)) {
            if (i > 1)
                dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
            else
                dp[i] = dp[i - 1];
        }
    }

    cout << dp[N] << endl;
}
