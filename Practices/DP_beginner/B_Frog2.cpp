/**
 *	author:  reiya0104
 *	created: 06.03.2021 13:15:53
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define MAX 100010

const ll INF = 1LL << 60;

template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

// 入力
int N;
ll h[MAX];

// DPテーブル
ll dp[MAX];

int main() {
    // 入力
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; ++i) cin >> h[i];

    // 初期化(最小化問題)
    for (int i = 0; i < MAX; ++i) dp[i] = INF;

    // 初期条件
    dp[0] = 0;

    // ループ
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j <= K; ++j) {
            chmin(dp[i + j], dp[i] + abs(h[i + j] - h[i]));
        }
    }

    // 答え
    cout << dp[N - 1] << endl;
}
