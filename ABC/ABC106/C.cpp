/**
 *	author:  reiya0104
 *	created: 16.05.2021 00:30:32
**/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    string S;
    ll K;
    cin >> S >> K;

    for (int i = 0; i < (int)S.size(); ++i) {
        if (i == K - 1) {
            cout << S.at(i) << endl;
            return 0;
        }
        if (S.at(i) != '1') {
            cout << S.at(i) << endl;
            return 0;
        }
    }
}
