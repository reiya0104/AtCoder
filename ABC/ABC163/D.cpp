/**
 *	author:  reiya0104
 *	created: 01.04.2021 01:20:35
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007LL;

ll N, K;

ll func(ll i) {
    return (- i * i + (N + 1) * i + 1) % MOD;
}

int main() {
    cin >> N >> K;
    ll res = 0LL;
    for (ll i = K; i <= N + 1; ++i) {
        res = (res + func(i)) % MOD;
    }

    cout << res << endl;

}
