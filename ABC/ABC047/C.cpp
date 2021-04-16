/**
 *	author:  reiya0104
 *	created: 23.03.2021 20:50:43
**/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;

int main() {
    string S;
    cin >> S;

    int res = 0;
    for (int i = 1; i < S.size(); ++i) {
        if (S.at(i - 1) != S.at(i)) ++res;
    }
    cout << res << endl;
}
