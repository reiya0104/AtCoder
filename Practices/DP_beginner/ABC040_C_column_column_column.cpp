/**
 *	author:  reiya0104
 *	created: 06.03.2021 12:10:20
 **/

#include <bits/stdc++.h>
using namespace std;
#define MAX 100100

const int INF = 1001001001;
template <class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return 1; } return 0; }

// 入力
int N;
int a[MAX];

// DP
int dp[MAX];

int main() {
    // 入力
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> a[i];

    // DP初期化
    for (int i = 0; i < MAX; ++i) dp[i] = INF;

    // 初期解
    dp[0] = 0;

    // ループ
    for (int i = 1; i < N; ++i) {
        chmin(dp[i], dp[i - 1] + abs(a[i] - a[i - 1]));
        if (i > 1) chmin(dp[i], dp[i - 2] + abs(a[i] - a[i - 2]));
    }

    cout << dp[N - 1] << endl;
}
