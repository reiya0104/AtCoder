#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;

// 2の素因数の個数
ll solve(ll n);
ll solve(ll n) {
    ll res = 0;
    while (!(n & 1) && n > 0) {
        ++res;
        n >>= 1;
    }
    return res;
}

int main() {
    int N;
    cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) cin >> a.at(i);

    ll res = 0;
    for (int i = 0; i < N; ++i) res += solve(a.at(i));
    cout << res << endl;
}
