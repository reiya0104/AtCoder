/**
 *	author:  reiya0104
 *	created: 23.04.2021 13:42:31
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;

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

// 最上位が n*10**k のルンルン数の個数
void runrunCount(int k, int n, ll &res) {
    // cout << "runrunCount(" << k << ", " << n << ", " << res << ")" << endl;
    if (k == 0) {
        ++res;
        return;
    }
    if (k == 1) {
        if (n == 0 || n == 9)
            res += 2;
        else
            res += 3;
    } else {
        if (n == 0 || n == 9) {
            runrunCount(k - 1, n, res);
            if (n == 0) runrunCount(k - 1, n + 1, res);
            if (n == 9) runrunCount(k - 1, n - 1, res);
        } else {
            runrunCount(k - 1, n - 1, res);
            runrunCount(k - 1, n, res);
            runrunCount(k - 1, n + 1, res);
        }
    }
}

int K;

vector<int> ans;

void solve() {
    bool flg = false;
    ll res = 0;
    ll res_pre = 0;
    for (int k = 0; k < 10; ++k) {
        for (int i = 1; i < 10; ++i) {
            res_pre = res;
            // cout << "runrunCount(" << k << ", " << i << ", " << res << ") = ";
            runrunCount(k, i, res);
            // cout << res << endl;
            if (K <= res) {
                flg = true;
                ans.assign(k + 1, 0);
                // cout << "ans.at(" << k << ") = " << i << endl;
                ans.at(0) = i;
                break;
            }
        }
        if (flg) break;
    }

    for (int k = 1; k < ans.size(); ++k) {
        res = res_pre;
        int i_s, i_e;
        i_s = max(ans.at(k - 1) - 1, 0);
        i_e = min(ans.at(k - 1) + 1, 9);
        for (int i = i_s; i <= i_e; ++i) {
            res_pre = res;
            // cout << "runrunCount(" << ans.size() - k - 1 << ", " << i << ", " << res << ") = ";
            runrunCount(ans.size() - k - 1, i, res);
            // cout << res << endl;
            if (K <= res) {
                ans.at(k) = i;
                break;
            }
        }
    }
}

int main() {
    cin >> K;
    solve();

    for (int i = 0; i < ans.size(); ++i) cout << ans.at(i);
    cout << endl;
    // int N;
    // cin >> N;
}
