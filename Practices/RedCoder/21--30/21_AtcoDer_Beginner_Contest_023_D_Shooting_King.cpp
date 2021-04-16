/**
 *	author:  reiya0104
 *	created: 21.03.2021 10:27:23
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll INF = 1001001001001001000;
const ll MAX = (1000000000LL + 1000000000LL * 100000LL) + 100LL;

// #define show_vec(vec)                          \
//     do {                                       \
//         cout << #vec " = {";                   \
//         for (int i = 0; i < vec.size(); ++i) { \
//             cout << vec.at(i);                 \
//             if (i != vec.size() - 1)           \
//                 cout << " ";                   \
//             else                               \
//                 cout << "}" << endl;           \
//         }                                      \
//     } while (0)

/* 風船が割られたときの高さがすべてX以下である
<-> tを時間とするとすべてのi=0, 1, 2, ..., N-1についてH_i+t*S_i<=X
<-> s<=(X-H_i)/S_i
<-> 風船iはfloor((X-H_i)/S_i)秒以内で割れる

風船が割られたときの高さがすべてX以下となるようなXを二分探索で求める

1. 風船iはfloor((X-H_i)/S_i)秒以内で割れる(X<=H_iのときは不適)
2. j秒以内で割ることができる風船が多くてもj+1個である
  */

int N;

bool isOK(vector<pair<ll, ll>> &hs, ll &X) {
    // i秒以内に割る風船の個数
    vector<int> T(N, 0);
    for (int i = 0; i < N; ++i) {
        ll index = (X - hs.at(i).first) / hs.at(i).second;
        if ((X - hs.at(i).first) < 0)
            return false;
        else if (index >= N)
            ++T.at(N - 1);
        else
            ++T.at((int)index);
    }
    int count = 0;

    // show_vec(T);

    for (int i = 0; i < N; ++i) {
        count += T.at(i);
        if (count > i + 1) return false;
    }
    return true;
}

ll binary_search(vector<pair<ll, ll>> &hs) {
    ll ng = -1;
    ll ok = MAX;
    while (abs(ng - ok) > 1) {
        ll mid = (ng + ok) / 2;
        // printf("mid = %lld, ng = %lld, ok = %lld\n", mid, ng, ok);
        // printf("isOK(N, hs, %lld) = %d\n", mid, isOK(N, hs, mid));
        if (isOK(hs, mid))
            ok = mid;
        else
            ng = mid;
    }
    return ok;
}

int main() {
    cin >> N;
    vector<pair<ll, ll>> hs(N);
    for (int i = 0; i < N; ++i) cin >> hs.at(i).first >> hs.at(i).second;

    cout << binary_search(hs) << endl;
}
