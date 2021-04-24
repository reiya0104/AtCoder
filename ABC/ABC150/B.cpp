/**
 *	author:  reiya0104
 *	created: 22.04.2021 00:03:35
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int res = 0;
    for (int i = 0; i < N - 2; ++i)
        if (S.at(i) == 'A' && S.at(i + 1) == 'B' && S.at(i + 2) == 'C') ++res;

    cout << res << endl;
}
