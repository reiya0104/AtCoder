/**
 *	author:  reiya0104
 *	created: 19.04.2021 23:39:45
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;

template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

int N, K;
int R, S, P;
string T;

int main() {
    cin >> N >> K;
    cin >> R >> S >> P;
    cin >> T;

    // i-1回目までの最大値
    // ( j = 0 : i-1  回目にrを出したとき
    // , j = 1 : i-1  回目にsを出したとき
    // , j = 2 : i-1  回目にpを出したとき)
    // ( k = 0 : i-1-K回目にrを出したとき
    // , k = 1 : i-1-K回目にsを出したとき
    // , k = 2 : i-1-K回目にpを出したとき)
    vector<vector<vector<int>>> dp(N + 1,
                                   vector<vector<int>>(3, vector<int>(3, 0)));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (T.at(i) == 'r') {
                    dp.at(i + 1).at(j).at(k);
                }
            }
        }
    }
}
