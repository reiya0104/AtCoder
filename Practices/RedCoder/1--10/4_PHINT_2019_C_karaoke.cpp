/**
 *	author:  reiya0104
 *	created: 15.03.2021 09:53:20
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001000;

int main() {
    // 入力
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) cin >> A.at(i).at(j);

    // for (int i = 0; i < N; ++i) {
    //     for (int j = 0; j < M; ++j) cout << A.at(i).at(j) << " ";
    //     cout << endl;
    // }

    // 二曲選ぶ(全探索)
    ll res = 0;
    for (int j1 = 0; j1 < M - 1; ++j1) {
        for (int j2 = j1 + 1; j2 < M; ++j2) {
            ll res0 = 0;
            for (int i = 0; i < N; ++i) {
                res0 += max(A.at(i).at(j1), A.at(i).at(j2));
            }
            if (res < res0) res = res0;
        }
    }
    cout << res << endl;
}
