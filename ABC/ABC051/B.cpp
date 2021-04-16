/**
 *	author:  reiya0104
 *	created: 10.04.2021 13:14:40
**/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;

int main() {
    int K, S;
    cin >> K >> S;
    
    ll res = 0;
    for (int i = 0; i <= K; i++) {
        for (int j = 0; j <= K; ++j) {
            int z = S - i - j;
            if (0 <= z && z <= K) ++res;
        }
    }
    cout << res << endl;
}
