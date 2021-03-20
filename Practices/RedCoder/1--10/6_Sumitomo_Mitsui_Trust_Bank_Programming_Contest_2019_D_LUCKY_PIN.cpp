/**
 *	author:  reiya0104
 *	created: 15.03.2021 10:46:13
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001000;

bool canMake(int n, string S) {
    assert(n >= 0 && n <= 999);
    string n_s = to_string(n);
    int t = 3 - n_s.size();
    for (int i = 0; i < t; ++i) {
        n_s = '0' + n_s;
    }
    bool b0 = false, b1 = false, b2 = false;
    for (int i = 0; i < S.size(); ++i) {
        if (b0) {
            if (b1) {
                if (b2) {
                    break;
                } else {
                    if (S.at(i) == n_s.at(2)) b2 = true;
                }
            } else {
                if (S.at(i) == n_s.at(1)) b1 = true;
            }
        } else {
            if (S.at(i) == n_s.at(0)) b0 = true;
        }
    }
    if (b2) return true;
    return false;
}

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int res = 0;
    for (int i = 0; i < 1000; ++i) {
        if (canMake(i, S)) ++res;
    }
    cout << res << endl;
}
