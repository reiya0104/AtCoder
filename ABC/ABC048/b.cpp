/**
 *	author:  reiya0104
 *	created: 06.04.2021 00:31:30
**/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;

int main() {
    ll a, b, x;
    cin >> a >> b >> x;
    ll n = b / x;
    ll m = a / x;
    if (x * m == a) --m;
    cout << n - m << endl;
}
