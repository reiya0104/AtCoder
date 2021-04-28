/**
 *	author:  reiya0104
 *	created: 24.04.2021 11:45:02
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;
const ll MOD = 1000000007;

int X, Y;

//  p x + q y = 1 となる x, y を求める
ll ExtGCD(ll p, ll q, ll &x, ll &y) {
    // cout << "ExtGCD(" << p << ", " << q << ")" << endl;
    if (q == 0) {
        x = 1;
        y = 0;
        // cout << "ExtGCD(" << p << ", " << q << ", " << x << ", " << y
        //      << ") = " << p << endl;
        return p;
    }
    ll gcd = ExtGCD(q, p % q, x, y);
    ll oldX = x;
    x = y;
    y = oldX - p / q * y;
    // cout << "ExtGCD(" << p << ", " << q << ", " << x << ", " << y
    //      << ") = " << gcd << endl;
    return gcd;
}

// MODの逆元を計算する
ll modInv(ll x) {
    ll a, b;
    ExtGCD(x, MOD, a, b);
    if (a < 0) a += MOD;
    return a;
}

ll Mul(ll a, ll b) {
    ll res = ((a % MOD) * (b % MOD)) % MOD;
    if (res < 0) res += MOD;
    return res;
}

ll Comb(ll n, ll r) {
    if (r == 0 || r == n) return 1;
    if (r == 1 || r == n - 1) return n;
    ll res = 1;
    for (int i = 1; i <= n; ++i) {
        res = Mul(res, i);
    }
    // cout << n << "! = " << res << endl;
    ll n_1 = 1, n_2 = 1;
    if (r >= n - r) r = n - r;

    for (int i = 1; i <= r; ++i) {
        n_1 = Mul(n_1, i);
    }
    n_2 = n_1;
    for (int i = r + 1; i <= n - r; ++i) {
        n_2 = Mul(n_2, i);
    }
    // cout << r << "! = " << n_1 << endl;
    // cout << n - r << "! = " << n_2 << endl;

    ll n_1_i = modInv(n_1);
    ll n_2_i = modInv(n_2);

    // cout << "modInv(" << r << "!) = " << n_1_i << endl;
    // cout << "modInv(" << n - r << "!) = " << n_2_i << endl;

    res = Mul(Mul(res, n_1_i), n_2_i);
    return res;
}

int main() {
    cin >> X >> Y;
    int x = 2 * X - Y;
    int y = -X + 2 * Y;
    if (x % 3 == 0 && y % 3 == 0) {
        x /= 3;
        y /= 3;
        cout << Comb(x + y, x) << endl;
    } else cout << 0 << endl;
}
