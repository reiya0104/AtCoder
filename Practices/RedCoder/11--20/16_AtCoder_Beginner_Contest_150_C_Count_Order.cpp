/**
 *	author:  reiya0104
 *	created: 19.03.2021 15:40:17
**/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;

int main() {
    int N;
    cin >> N;
    vector<int> P(N);
    vector<int> Q(N);
    for (int i = 0; i < N; ++i) cin >> P.at(i);
    for (int i = 0; i < N; ++i) cin >> Q.at(i);

    vector<int> A(N);
    for (int i = 0; i < N; ++i) A.at(i) = i + 1;

    int p, q;
    int i = 1;
    do {
        if (A == P) p = i;
        if (A == Q) q = i;
        ++i;
    } while(next_permutation(A.begin(), A.end()));

    cout << abs(p - q) << endl;
}
