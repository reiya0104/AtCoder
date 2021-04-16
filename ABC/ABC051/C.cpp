/**
 *	author:  reiya0104
 *	created: 09.04.2021 00:03:54
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    int a = tx - sx, b = ty - sy;

    string res;
    for (int i = 0; i < b; ++i) res += "U";
    for (int i = 0; i < a; ++i) res += "R";
    for (int i = 0; i < b; ++i) res += "D";
    for (int i = 0; i < a; ++i) res += "L";

    res += "L";
    for (int i = 0; i < b + 1; ++i) res += "U";
    for (int i = 0; i < a + 1; ++i) res += "R";
    res += "D";

    res += "R";
    for (int i = 0; i < b + 1; ++i) res += "D";
    for (int i = 0; i < a + 1; ++i) res += "L";
    res += "U";

    cout << res << endl;
}
