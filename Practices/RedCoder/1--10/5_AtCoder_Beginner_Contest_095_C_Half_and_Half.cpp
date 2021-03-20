/**
 *	author:  reiya0104
 *	created: 15.03.2021 10:07:28
 **/

#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001000;

template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    int A, B, C;
    int X, Y;
    cin >> A >> B >> C >> X >> Y;
    int diff = 2 * C - A - B;
    int res = INF;
    if (diff >= 0) {
        res = X * A + Y * B;
    } else {
        for (int k = min(X, Y); k <= max(X, Y); ++k) {
            chmin(res, max(X - k, 0) * A + max(Y - k, 0) * B + 2 * k * C);
        }
    }
    cout << res << endl;
}
