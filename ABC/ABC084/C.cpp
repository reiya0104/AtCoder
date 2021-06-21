#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;

int N;
vector<int> C, S, F;

// 地点iに時刻tでついたとき，
// 地点i+1に辿り着く時刻
ll solve(int i, ll t) {
    if (t < S.at(i)) return S.at(i) + C.at(i);
    ll t_pos = t;
    while (t_pos % F.at(i) != 0) ++t_pos;
    return t_pos + C.at(i);
}

ll func(int i) {
    ll res = 0;
    for (int j = i; j < N - 1; ++j) {
        res = solve(j, res);
    }
    return res;
}

int main() {
    cin >> N;
    C.resize(N - 1);
    S.resize(N - 1);
    F.resize(N - 1);
    for (int i = 0; i < N - 1; ++i) cin >> C.at(i) >> S.at(i) >> F.at(i);

    for (int i = 0; i < N; ++i) {
        cout << func(i) << endl;
    }
}
