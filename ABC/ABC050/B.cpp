/**
 *	author:  reiya0104
 *	created: 10.04.2021 23:52:12
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;

int main() {
    int N;
    cin >> N;
    vector<int> T(N);
    for (int i = 0; i < N; ++i) cin >> T.at(i);
    int M;
    cin >> M;
    vector<int> P(M), X(M);
    for (int i = 0; i < M; ++i) cin >> P.at(i) >> X.at(i);

    ll sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += T.at(i);
    }

    vector<int> res(M);
    for (int i = 0; i < M; ++i) {
        res.at(i) = sum - (T.at(P.at(i) - 1) - X.at(i));
    }

    for (int i = 0; i < M; ++i) {
        cout << res.at(i) << endl;
    }
}
