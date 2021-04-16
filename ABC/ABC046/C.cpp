/**
 *	author:  reiya0104
 *	created: 03.04.2021 00:07:20
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;

int N;
vector<int> T, A;

// dp.at(i)
// i回目において二人の総数のそれぞれの最小値
vector<pair<ll, ll>> dp;

// dpの最後はN回目->dp.at(N+1)の値

int main() {
    cin >> N;
    T.resize(N);
    A.resize(N);
    for (int i = 0; i < N; ++i) cin >> T.at(i) >> A.at(i);

    dp.resize(N + 2);

    for (int i = 0; i < N; ++i) {
        ll t, a;
        if (i > 0)
            t = dp.at(i - 1).first, a = dp.at(i - 1).second;
        else
            t = 1, a = 1;
        if (t % T.at(i) != 0) t = ((t / T.at(i)) + 1) * T.at(i);
        if (a % A.at(i) != 0) a = ((a / A.at(i)) + 1) * A.at(i);

        ll per = max(t / T.at(i), a / A.at(i));
        t = per * T.at(i);
        a = per * A.at(i);
        dp.at(i) = make_pair(t, a);
    }
    ll res = dp.at(N - 1).first + dp.at(N - 1).second;
    cout << res << endl;
}
