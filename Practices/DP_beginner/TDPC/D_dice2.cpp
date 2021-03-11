#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001000;

bool set_prime(ll x, vector<int> &prime) {
    vector<int> primes = {2, 3, 5};
    for (int i = 0; i < primes.size(); ++i) {
        int count = 0;
        while (x % primes.at(i) == 0) {
            x /= primes.at(i);
            count++;
        }
        prime.at(i) = count;
    }
    if (x == 1) return true;
    return false;
}

// void show(vector<vector<vector<vector<double>>>> &dp, vector<int> &primeD) {
//     for (int i = 0; i < dp.size(); ++i) {
//         for (int j = 0; j <= primeD.at(0); ++j) {
//             for (int k = 0; k <= primeD.at(1); ++k) {
//                 for (int l = 0; l <= primeD.at(2); ++l) {
//                     cout << "dp.at(" << i << ").at(" << j << ").at(" << k
//                          << ").at(" << l << ") = " << dp.at(i).at(j).at(k).at(l)
//                          << endl;
//                 }
//             }
//         }
//         cout << endl;
//     }
// }

int main() {
    // 入力
    int N;
    ll D;
    cin >> N >> D;

    // Dを素因数分解
    // 左から2, 3, 5の指数
    vector<int> primeD(3);
    if (!(set_prime(D, primeD))) {
        cout << 0 << endl;
        return 0;
    }

    // DPデータ
    // dp.at(i).at(j):=(i-1)番までのサイコロの出目の積を{2, 3, 5}の指数で並べた
    vector<vector<vector<vector<double>>>> dp(
        N + 1, vector<vector<vector<double>>>(
                   60, vector<vector<double>>(38, vector<double>(26, 0))));

    // 1~6の素因数分解
    vector<vector<int>> primeS(7, {0, 0, 0});

    // DP初期値
    for (int i = 1; i <= 6; ++i) {
        vector<int> primes(3);
        set_prime(i, primes);
        primeS.at(i) = primes;
        int j_m = (primeS.at(i).at(0) < primeD.at(0)) ? primeS.at(i).at(0)
                                                      : primeD.at(0);
        int k_m = (primeS.at(i).at(1) < primeD.at(1)) ? primeS.at(i).at(1)
                                                      : primeD.at(1);
        int l_m = (primeS.at(i).at(2) < primeD.at(2)) ? primeS.at(i).at(2)
                                                      : primeD.at(2);
        dp.at(1).at(j_m).at(k_m).at(l_m) += 1 / 6.0;
    }

    // DPループ
    for (int i = 1; i < N; ++i) {
        // cout << i << endl;
        for (int j = 0; j <= primeD.at(0); ++j) {
            for (int k = 0; k <= primeD.at(1); ++k) {
                for (int l = 0; l <= primeD.at(2); ++l) {
                    for (int m = 1; m <= 6; ++m) {
                        int j_m = (j + primeS.at(m).at(0) < primeD.at(0))
                                      ? (j + primeS.at(m).at(0))
                                      : primeD.at(0);
                        int k_m = (k + primeS.at(m).at(1) < primeD.at(1))
                                      ? (k + primeS.at(m).at(1))
                                      : primeD.at(1);
                        int l_m = (l + primeS.at(m).at(2) < primeD.at(2))
                                      ? (l + primeS.at(m).at(2))
                                      : primeD.at(2);
                        dp.at(i + 1).at(j_m).at(k_m).at(l_m) +=
                            dp.at(i).at(j).at(k).at(l) / 6;
                    }
                }
            }
        }
    }

    cout << dp.at(N).at(primeD.at(0)).at(primeD.at(1)).at(primeD.at(2)) << endl;
}
