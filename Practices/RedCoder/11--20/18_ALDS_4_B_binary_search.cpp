/**
 *	author:  reiya0104
 *	created: 19.03.2021 23:22:54
 **/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;

// indexが条件を満たすかどうか
bool isOK(vector<int> &vec, int &index, int &key) {
    if (vec.at(index) >= key)
        return true;
    else
        return false;
}

int binary_search(vector<int> &vec, int key) {
    int ng = -1;
    int ok = vec.size();
    while (abs(ng - ok) > 1) {
        int mid = (ok + ng) / 2;
        if (isOK(vec, mid, key))
            ok = mid;
        else
            ng = mid;
    }
    return ok;
}

int main() {
    int n;
    cin >> n;
    vector<int> S(n);
    for (int i = 0; i < n; ++i) cin >> S.at(i);
    int q;
    cin >> q;
    vector<int> T(q);
    for (int i = 0; i < q; ++i) cin >> T.at(i);

    int res = 0;
    // 二分探索
    for (int i = 0; i < q; ++i) {
        int st = binary_search(S, T.at(i));
        if (st != S.size() && S.at(st) == T.at(i)) ++res;
    }

    cout << res << endl;
}
