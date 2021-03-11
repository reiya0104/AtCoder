#include <iostream>
#include <vector>
#define MAX 1000100

template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

// 入力
int N;
std::vector<std::vector<int> > a(MAX, std::vector<int>(3));

// DPテーブル
std::vector<std::vector<int> > dp(MAX, std::vector<int>(3, 0));

int main() {
    // 入力
    int N;
    std::cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < 3; ++j) std::cin >> a.at(i).at(j);

    // 初期化は既に 0 に初期化される
    // 初期条件も既に 0 で OK

    // ループ
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (j == k) continue;
                chmax(dp[i + 1][k], dp[i][j] + a[i][k]);
            }
        }
    }

    // 答え
    int res = 0;
    for (int j = 0; j < 3; ++j) chmax(res, dp[N][j]);
    std::cout << res << std::endl;
}
