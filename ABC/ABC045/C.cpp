/**
 *	author:  reiya0104
 *	created: 10.03.2021 13:45:06
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001000;

ll calc(string S) {
    // cout << S << endl;
    ll res = 0;
    ll num = 0;
    for (int i = 0; i < S.size(); ++i) {
        if (S.at(i) == '+') {
            res += num;
            num = 0;
        } else {
            num = num * 10 + (S.at(i) - '0');
        }
    }
    res += num;
    return res;
}

ll next(string pre, string &S, int i) {
    // cout << "next(" << pre << ", " << i << ")" << endl;
    if (i < S.size()) {
        if (pre.empty()) {
            return next({S.at(i)}, S, i + 1);
        } else {
            return (next(pre + S.at(i), S, i + 1) +
                    next(pre + "+" + S.at(i), S, i + 1));
        }
    }
    return calc(pre);
}

int main() {
    // cout << calc("1+12+3") << endl;
    // cout << calc("112+35") << endl;
    // cout << calc("1+12+3456") << endl;
    // cout << calc("13") << endl;
    // cout << (2 << 10) << endl;
    // return 0;

    // 入力
    string S;
    cin >> S;

    cout << next("", S, 0) << endl;
}
