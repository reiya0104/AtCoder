/**
 *	author:  reiya0104
 *	created: 04.04.2021 01:51:49
**/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A.at(i);

    vector<ll> S(N, 0), T(N, 0);
    for (int i = 0; i < N; ++i) {
        int s = i + A.at(i);
        int t = i - A.at(i);
        if (s < N) ++S.at(s);
        if (t >= 0) ++T.at(t);
    }

    ll res = 0;
    for (int i = 0; i < N; ++i) {
        res += S.at(i) * T.at(i);
    }
    cout << res << endl;
}
