/**
 *	author:  reiya0104
 *	created: 25.03.2021 22:24:52
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define show_vec(vec)                          \
    do {                                       \
        cout << #vec " = {";                   \
        for (int i = 0; i < vec.size(); ++i) { \
            cout << vec.at(i);                 \
            if (i != vec.size() - 1)           \
                cout << " ";                   \
            else                               \
                cout << "}" << endl;           \
        }                                      \
    } while (0)

const int INF = 1001001000;

int N, x;
void solve(int i, ll &res, vector<int> &a) {
    int t = min(a.at(i + 1), a.at(i) + a.at(i + 1) - x);
    if (t > 0) {
        if (t == a.at(i) + a.at(i + 1) - x) {
            res += t;
        } else if (t >= 0) {
            res += t + a.at(i) - x;
        }
        a.at(i + 1) -= t;
    }
}

int main() {
    cin >> N;
    cin >> x;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a.at(i);

    ll res = 0;
    // show_vec(a);
    for (int i = 0; i < N - 1; ++i) {
        solve(i, res, a);
        // show_vec(a);
    }
    cout << res << endl;
}
