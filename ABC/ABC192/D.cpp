#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;


ll MAX = 9223372036854775807;

ll n_to_ten(string x, ll n) {
    ll res = 0;
    ll base = 1;
    for (int i = 0; i < x.size(); ++i) {
        if (i != 0) {
            ll old_base = base;
            base *= n;
            if (base / n != old_base || base < 1) return MAX;
        }
        ll old_res = res;
        res += (ll)(x.at(x.size() - i - 1) - '0') * base;
        if (res < old_res) return MAX;
		// cout << "i = " << i << ", res = " << res << ", base = " << base << endl;
    }
    return res;
}


int main() {
    string X;
    cin >> X;
    ll M;
    cin >> M;

    vector<int> X_vec(X.size());
    for (int i = 0; i < X.size(); ++i)
        X_vec.at(i) = X.at(X.size() - i - 1) - '0';
    int d = 0;
    for (int i = 0; i < X.size(); ++i)
        if (d < (X.at(i) - '0')) d = (X.at(i) - '0');
    // cout << "d = " << d << endl;

    ll bound;
    if (n_to_ten(X, MAX) == M) {
        bound = MAX;
    } else {
        ll upp = MAX;
        ll low = d;
        while (upp - low > 1) {
            ll mid = upp / 2 + low / 2 + ((upp & 1) && (low & 1));
            // cout << "upp = " << upp << ", low = " << low << ", mid = " << mid << ", n_to_ten(X, mid) = " << n_to_ten(X, mid) << endl;
            if (n_to_ten(X, mid) > M) {
                upp = mid;
            } else low = mid;
        }
        bound = low;
    }

    // cout << "bound = " << bound << endl;

    ll res = bound - d;
    cout << res << endl;
}
