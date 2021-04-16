/**
 *	author:  reiya0104
 *	created: 08.04.2021 00:47:03
**/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;
const ll MOD = 1000000007;

ll solve(int n) {
    ll res = 1;
    ll a = 2;
    while (n > 0) {
        if (n & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return res;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A.at(i);

    vector<int> K((N + 1) / 2, 0);
    for (int i = 0; i < N; ++i) {
        ++K.at(A.at(i) / 2);
    }

    bool flag = true;
    if (N & 1) {
        if (K.at(0) != 1) flag = false;
    } else {
        if (K.at(0) != 2) flag = false;
    }
    for (int i = 1; i < N / 2; ++i) {
        if (K.at(i) != 2) flag = false;
    }

    if (flag) cout << solve(N / 2) << endl;
    else cout << 0 << endl;
}
