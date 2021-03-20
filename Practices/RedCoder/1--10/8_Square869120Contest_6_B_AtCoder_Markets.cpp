/**
 *	author:  reiya0104
 *	created: 15.03.2021 18:33:04
**/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001000;

int Time(int s, int g, pair<int, int> ab) {
    return abs(s - ab.first) + abs(g - ab.second) + abs(ab.second - ab.first);
}

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> AB(N);
    for (int i = 0; i < N; ++i) cin >> AB.at(i).first >> AB.at(i).second;
    sort(AB.begin(), AB.end());

    ll sumA = 0, sumB = 0;
    for (int i = 0; i < N; ++i) {
        sumA += AB.at(i).first;
        sumB += AB.at(i).second;
    }
    ll avgA = sumA / N, avgB = sumB / N;
    printf("avgA = %lld, avgB = %lld\n", avgA, avgB);

    ll res = 0;
    ll res_s = 0;
    ll res_ss = 0;
    for (int i = 0; i < N; ++i) {
        res_s += Time(avgA, avgB, AB.at(i));
        res_ss += (ll)Time(avgA, avgB, AB.at(i)) * (ll)Time(avgA, avgB, AB.at(i));
    }
    res = res_s;
    cout << res_s << " " << res_ss << endl;

    res_s = 0;
    res_ss = 0;
    for (int i = 0; i < N; ++i) {
        res_s += Time(avgA + 1, avgB, AB.at(i));
        res_ss += (ll)Time(avgA + 1, avgB, AB.at(i)) * (ll)Time(avgA + 1, avgB, AB.at(i));
    }
    if (res > res_s) res = res_s;
    cout << res_s << " " << res_ss << endl;

    res_s = 0;
    res_ss = 0;
    for (int i = 0; i < N; ++i) {
        res_s += Time(avgA, avgB + 1, AB.at(i));
        res_ss += (ll)Time(avgA, avgB + 1, AB.at(i)) * (ll)Time(avgA, avgB + 1, AB.at(i));
    }
    if (res > res_s) res = res_s;
    cout << res_s << " " << res_ss << endl;

    res_s = 0;
    res_ss = 0;
    for (int i = 0; i < N; ++i) {
        res_s += Time(avgA + 1, avgB + 1, AB.at(i));
        res_ss += (ll)Time(avgA + 1, avgB + 1, AB.at(i)) * (ll)Time(avgA + 1, avgB + 1, AB.at(i));
    }
    if (res > res_s) res = res_s;
    cout << res_s << " " << res_ss << endl;

    res_s = 0;
    res_ss = 0;
    for (int i = 0; i < N; ++i) {
        res_s += Time(14, 64, AB.at(i));
        res_ss += (ll)Time(14, 64, AB.at(i)) * (ll)Time(14, 64, AB.at(i));
    }
    if (res > res_s) res = res_s;
    cout << res_s << " " << res_ss << endl;

    cout << res << endl;
}
