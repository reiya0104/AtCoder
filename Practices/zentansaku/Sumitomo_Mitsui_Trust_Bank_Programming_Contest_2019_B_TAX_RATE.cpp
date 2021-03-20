/**
 *	author:  reiya0104
 *	created: 17.03.2021 15:14:34
**/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001000;

int main() {
    int N;
    cin >> N;
    double k = N / 1.08;
    int k1 = (int)k;
    int k2 = k1 + 1;
    int n1 = (int)(k1 * 1.08);
    int n2 = (int)(k2 * 1.08);
    if (n1 == N) {
        cout << k1 << endl;
    } else if (n2 == N) {
        cout << k2 << endl;
    } else {
        cout << ":(" << endl;
    }
}
