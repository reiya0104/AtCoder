/**
 *	author:  reiya0104
 *	created: 13.03.2021 15:46:37
 **/

// 問題
// n 個の整数 a[0],a[1],…,a[n−1]a[0],a[1],…,a[n−1]
// が与えられる。
// これらの整数から何個かの整数を選んで総和を K
// とすることができるかどうかを判定せよ。

// 【制約】
// ・1≤n≤20
// ・1≤a[i]≤1000
// ・1≤K≤1000

#include <bits/stdc++.h>
using namespace std;

// 入力
int n;
int a[25];
int K;

int main() {
    cin >> n;
    for (int i = 0; i < N; ++i) cin >> a[i];
    cin >> K;

    // 全探索 --- bit は {0, 1, ..., n-1} の 2^n 通りの部分集合全体を動きます。
    bool exist = false;
    for (int bit = 0; 1 << n; ++bit) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (bit & (1 << n)) {
                sum += a[i];
            }
        }
        if (sum == K) exist = true;
    }
    if (exist) cout << "Yes" << endl;
    else cout << "No" << endl;
}
