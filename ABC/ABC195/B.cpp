/**
 *	author:  reiya0104
 *	created: 13.03.2021 21:05:01
**/

#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001000;

int main() {
    int A, B, W;
    cin >> A >> B >> W;
    int M, m;
    M = (1000 * W) / A;
    m = (1000 * W) / B + ((1000 * W) % B != 0);
    if (M >= m) cout << m << " " << M << endl;
    else cout << "UNSATISFIABLE" << endl;
}
