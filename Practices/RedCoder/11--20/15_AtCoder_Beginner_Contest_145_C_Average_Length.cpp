/**
 *	author:  reiya0104
 *	created: 19.03.2021 14:19:59
**/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;

long double dist(pii &p, pii &q) {
    return sqrt((long double)((q.first - p.first) * (q.first - p.first) + (q.second - p.second) * (q.second - p.second)));
}

int main() {
    int N;
    cin >> N;
    vector<pii> xy(N);
    for (int i = 0; i < N; ++i) cin >> xy.at(i).first >> xy.at(i).second;

    sort(xy.begin(), xy.end());

    long double sum = 0;
    int count = 0;
    do {
        for (int i = 1; i < N; ++i) {
            sum += dist(xy.at(i - 1), xy.at(i));
        }
        ++count;
    } while(next_permutation(xy.begin(), xy.end()));

    long double res = sum / count;
    printf("%Lf\n", res);
    // cout << res << endl;

    // long double ans;
    // cin >> ans;
    // cout << "絶対誤差" << abs(res - ans) << endl;
    // cout << "相対誤差" << abs((res - ans) / ans) << endl;
}
