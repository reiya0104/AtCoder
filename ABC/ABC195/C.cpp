/**
 *	author:  reiya0104
 *	created: 13.03.2021 21:10:49
**/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    string S = to_string(N);
    int s = S.size();

    ll pre = 0;

    if (1 <= s && s <= 3) {
        cout << 0 << endl;
    }
    if (4 <= s && s <= 6) {
        cout << (N - 1000 + 1) << endl;
    }
    pre += 999000;
    if (7 <= s && s <= 9) {
        cout << (pre + 2LL * (N - 1000000LL + 1)) << endl;
    }
    pre += 2 * 999000000LL;
    if (10 <= s && s <= 12) {
        cout << (pre + 3LL * (N - 1000000000LL + 1)) << endl;
    }
    pre += 3 * 999000000000LL;
    if (13 <= s && s <= 15) {
        cout << (pre + 4LL * (N - 1000000000000LL + 1)) << endl;
    }
    pre += 4 * 999000000000000LL;
    if (16 <= s && s <= 18) {
        cout << (pre + 5LL * (N - 1000000000000000LL + 1)) << endl;
    }
}
