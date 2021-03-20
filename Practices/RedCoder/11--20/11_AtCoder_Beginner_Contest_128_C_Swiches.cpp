/**
 *	author:  reiya0104
 *	created: 18.03.2021 16:28:19
**/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001000;

int main() {
    // 入力
    int N, M;
    cin >> N >> M;
    vector<int> k(M);
    vector<vector<bool>> s(M, vector<bool>(N, false));
    for (int i = 0; i < M; ++i) {
        cin >> k.at(i);
        for (int j = 0; j < k.at(i); ++j) {
            int x;
            cin >> x;
            s.at(i).at(x - 1) = true;
        }
    }
    vector<int> p(M);
    for (int i = 0; i < M; ++i) cin >> p.at(i);

    int res = 0;
    // bit全探索
    for (int i = 0; i < (1 << N); ++i) {
        // bitに格納
        vector<int> bit;
        for (int j = 0; j < N; ++j) {
            if (i & (1 << j)) bit.push_back(j);
        }

        // メイン処理
        bool exist = true;
        for (int j = 0; j < M; ++j) {
            int on = 0;
            for (int k = 0; k < bit.size(); ++k) {
                if (s.at(j).at(bit.at(k))) ++on;
            }
            if (on % 2 != p.at(j)) {
                exist = false;
                break;
            }
        }
        if (exist) ++res;
    }

    // 答え
    cout << res << endl;
}
