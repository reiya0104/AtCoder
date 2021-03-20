/**
 *	author:  reiya0104
 *	created: 20.03.2021 11:00:53
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;

bool isOK(vector<int> &vec, int &index, int &key) {
    if (vec.at(index) >= key)
        return true;
    else
        return false;
}

int binary_search(vector<int> &vec, int key) {
    int ng = -1;
    int ok = vec.size();
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (isOK(vec, mid, key))
            ok = mid;
        else
            ng = mid;
    }
    return ok;
}

int main() {
    // 入力
    int d, n, m;
    cin >> d >> n >> m;
    vector<int> dn(n + 1), kn(m);
    for (int i = 1; i < n; ++i) cin >> dn.at(i);
    for (int i = 0; i < m; ++i) cin >> kn.at(i);
    dn.at(0) = 0;
    dn.at(n) = d;

    sort(dn.begin(), dn.end());
    sort(kn.begin(), kn.end());

    // 宅配ごとにループ
    int res = 0;
    for (int i = 0; i < m; ++i) {
        int S = binary_search(dn, kn.at(i));

        if (S > 0)
            res += min(abs(kn.at(i) - dn.at(S - 1)), abs(dn.at(S) - kn.at(i)));
        else
            res += abs(dn.at(S) - kn.at(i));
    }
    cout << res << endl;
}
