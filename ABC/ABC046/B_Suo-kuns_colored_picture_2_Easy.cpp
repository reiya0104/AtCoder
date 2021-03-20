/**
 *	author:  reiya0104
 *	created: 16.03.2021 07:51:59
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;

int area(int r, int l, int d, int u) {
    if (r < l && d < u) {
        return (l - r) * (u - d);
    }
    return 0;
}

int area(tuple<int, int, int, int> rec) {
    int r, l, d, u;
    tie(r, l, d, u) = rec;
    return (area(r, l, d, u));
}

int main() {
    // 入力
    int W, H, N;
    cin >> W >> H >> N;
    vector<pii> xy(N);
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
        cin >> xy.at(i).first >> xy.at(i).second >> a.at(i);

    // 白い部分は長方形の形を保つ
    // 左から(左側のx座標)->(右側のx座標)->(下側のy座標)->(上側のy座標)
    tuple<int, int, int, int> rec = make_tuple(0, W, 0, H);

    for (int i = 0; i < N; ++i) {
        if (a.at(i) == 1) {
            if (xy.at(i).first > get<0>(rec)) {
                get<0>(rec) = xy.at(i).first;
            }
        }
        if (a.at(i) == 2) {
            if (xy.at(i).first < get<1>(rec)) {
                get<1>(rec) = xy.at(i).first;
            }
        }
        if (a.at(i) == 3) {
            if (xy.at(i).second > get<2>(rec)) {
                get<2>(rec) = xy.at(i).second;
            }
        }
        if (a.at(i) == 4) {
            if (xy.at(i).second < get<3>(rec)) {
                get<3>(rec) = xy.at(i).second;
            }
        }
    }

    cout << area(rec) << endl;
}
