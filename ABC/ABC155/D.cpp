/**
 *	author:  reiya0104
 *	created: 09.05.2021 00:10:22
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;
#define MAX 1000000000000000001LL

int N;
ll K;
vector<ll> A;

// int lowerCount(ll num, bool &exist) {
ll lowerCount(ll num) {
    vector<ll> A_copy = A;

    // cout << "  num = " << num << endl;

    ll res = 0;
    for (int i = 0; i < N; ++i) {
        ll a = A_copy.at(A_copy.size() - 1);
        A_copy.pop_back();

        // cout << "    a = " << a << ", ";
        // cout << "A_copy = {";
        // for (int j = 0; j < A_copy.size(); ++j) {
        //     cout << A_copy.at(j);
        //     if (j != A_copy.size() - 1) cout << ", ";
        // }
        // cout << "}, " << endl;

        ll ng, ok;

        if (a >= 0) {
            ng = -1;
            ok = A_copy.size();
        } else {
            ng = A_copy.size();
            ok = -1;
        }

        while (abs(ng - ok) > 1) {
            ll mid = (ng + ok) / 2;

            ll times = A_copy.at(mid) * a;
            // cout << "      ok = " << ok << ", ng = " << ng << ", A_copy.at("
            //      << mid << ") * " << a << " = " << times << endl;

            // if (num == times) {
            //     exist = true;
            //     // ok = mid;
            //     ng = mid;
            //     // break;
            // } else if (num > times)
            //     ng = mid;
            if (num >= times)
                ng = mid;
            else
                ok = mid;
        }

        if (a >= 0) {
            res += ok;
            // cout << "    res += " << ok << endl;
        } else {
            res += (A_copy.size() - ok - 1);
            // cout << "    res += " << A_copy.size() - ok - 1 << endl;
        }
    }
    // cout << "  res = " << res << ", exist = " << (exist ? "true" : "false")
    //  << endl;

    return res;
}

ll solve() {
    ll ng = -MAX;
    ll ok = MAX;

    while (abs(ng - ok) > 1) {
        ll mid = (ng + ok) / 2;
        ll lowerCount_mid = lowerCount(mid);
        ll lowerCount_mid1 = lowerCount(mid - 1);
        // cout << "ok = " << ok << ", ng = " << ng << ", lowerCount(" << mid
        //      << ") = " << lowerCount_mid << endl;

        if (lowerCount_mid1 < K && K <= lowerCount_mid) return mid;
        if (lowerCount_mid >= K)
            ok = mid;
        else
            ng = mid;
    }
    return ok;
}

int main() {
    cin >> N >> K;
    A.resize(N);
    for (int i = 0; i < N; ++i) cin >> A.at(i);
    sort(A.begin(), A.end());

    // bool exist;
    // int mm = 25;
    // for (int i = -mm; i <= mm; ++i) {
    //     cout << "lowerCount(" << i << ") = " << lowerCount(i)
    //          << endl;
    // }

    ll res = solve();
    cout << res << endl;
}
