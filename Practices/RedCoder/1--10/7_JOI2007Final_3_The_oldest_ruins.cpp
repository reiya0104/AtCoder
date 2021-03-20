/**
 *	author:  reiya0104
 *	created: 15.03.2021 12:34:54
 **/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001000;

template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

int AreaSquare(pair<int, int> a, pair<int, int> b) {
    return (a.first - b.first) * (a.first - b.first) +
           (a.second - b.second) * (a.second - b.second);
}

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> data(N);
    for (int i = 0; i < N; ++i) cin >> data.at(i).first >> data.at(i).second;
    sort(data.begin(), data.end());

    int res = 0;
    for (int i1 = 0; i1 < N - 1; ++i1) {
        int x1 = data.at(i1).first;
        int y1 = data.at(i1).second;
        for (int i2 = i1; i2 < N; ++i2) {
            int x2 = data.at(i2).first;
            int y2 = data.at(i2).second;
            int x_sub = x2 - x1;
            int y_sub = y2 - y1;
            if (x_sub == 0 && y_sub == 0) continue;
            if (y_sub < 0) continue;

            if ((((x1 - y1) + (x2 + y2)) & 1) || (((x1 + y1) - (x2 - y2)) & 1))
                continue;
            int x3 = ((x1 - y1) + (x2 + y2)) / 2;
            int y3 = ((x1 + y1) - (x2 - y2)) / 2;
            int x4 = ((x1 + y1) + (x2 - y2)) / 2;
            int y4 = (-(x1 - y1) + (x2 + y2)) / 2;

            if (x3 > x4) {
                swap(x3, x4);
                swap(y3, y4);
            }
            if (x3 == x4) {
                if (y3 > y4) {
                    swap(x3, x4);
                    swap(y3, y4);
                }
            }

            auto itr1_b = data.begin();
            auto itr1_e = data.end();
            auto itr2_b = data.begin();
            auto itr2_e = data.end();

            if (y_sub == 0) {
                itr1_b = data.begin() + i1;
                itr1_e = data.begin() + i2;
            } else if (x_sub == 0) {
                itr1_b = data.begin();
                itr1_e = data.begin() + i1;
            } else if (x_sub == y_sub) {
                itr1_b = data.begin() + i1;
                itr1_e = data.begin() + i2;
            } else if (x_sub < y_sub) {
                itr1_b = data.begin();
                itr1_e = data.begin() + i1;
            } else if (x_sub > y_sub) {
                itr1_b = data.begin() + i1;
                itr1_e = data.begin() + i2;
            }

            auto itr1 = lower_bound(itr1_b, itr1_e, make_pair(x3, y3));

            if (itr1 != itr1_e && *itr1 == make_pair(x3, y3)) {
                if (y_sub == 0) {
                    itr2_b = data.begin() + distance(data.begin(), itr1);
                    itr2_e = data.begin() + i2;
                } else if (x_sub == 0) {
                    itr2_b = data.begin() + i2;
                    itr2_e = data.end();
                } else if (x_sub == y_sub) {
                    itr2_b = data.begin() + distance(data.begin(), itr1);
                    itr2_e = data.begin() + i2;
                } else if (x_sub < y_sub) {
                    itr2_b = data.begin() + i2;
                    itr2_e = data.end();
                } else if (x_sub > y_sub) {
                    itr2_b = data.begin() + distance(data.begin(), itr1);
                    itr2_e = data.begin() + i2;
                }
                auto itr2 = lower_bound(itr2_b, itr2_e, make_pair(x4, y4));
                if (itr2 != itr2_e && *itr2 == make_pair(x4, y4)) {
                    chmax(res, AreaSquare(data.at(i1), make_pair(x3, y3)));
                }
            }
        }
    }

    cout << res << endl;
}
