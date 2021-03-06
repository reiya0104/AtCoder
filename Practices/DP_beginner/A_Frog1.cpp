/**
 *	author:  reiya0104
 *	created: 06.03.2021 11:52:30
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
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> h[i];

    // 初期化(最小化問題)
    for (int i = 0; i < MAX; ++i) dp[i] = INF;

    // 初期条件
    dp[0] = 0;

    // ループ
    for (int i = 1; i < N; ++i) {
        chmin(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
        if (i > 1) {
            chmin(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
        }
    }

    // 答え
    cout << dp[N - 1] << endl;
}
