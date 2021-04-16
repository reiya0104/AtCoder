/**
 *	author:  reiya0104
 *	created: 22.03.2021 00:52:41
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;

// 入力
int N, M;
int X, Y;
vector<int> a, b;

int main() {
    cin >> N >> M >> X >> Y;
    a.resize(N);
    b.resize(M);
    for (int i = 0; i < N; ++i) cin >> a.at(i);
    for (int i = 0; i < M; ++i) cin >> b.at(i);

    int a_index = 0;
    int b_index = 0;
    int key = a.at(a_index);
    int res = 0;

    auto a_itr = a.begin();
    auto b_itr = b.begin();

    while (a_itr != a.end() && b_itr != b.end()) {
        key += X;
        // ++a_index;
        a_index = distance(a.begin(), a_itr) + 1;
        b_itr = lower_bound(b.begin() + b_index, b.end(), key);
        if (b_itr == b.end()) break;
        key = *b_itr;

        key += Y;
        // ++b_index;
        b_index = distance(b.begin(), b_itr) + 1;
        a_itr = lower_bound(a.begin() + a_index, a.end(), key);
        // if (a_itr == a.end()) break;
        key = *a_itr;

        ++res;
    }

    cout << res << endl;
}
