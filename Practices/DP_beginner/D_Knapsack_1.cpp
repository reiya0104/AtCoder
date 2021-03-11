#include <iostream>
#include <vector>
#define MAX 10001000

template <class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return 1; } return 0; }

// 入力
int N, W;
std::vector<int> weight(110, 0), value(110, 0);

// DPテーブル
std::vector<std::vector<int> > dp(110, std::vector<int>(MAX, 0));

int main() {
    // 入力
    std::cin >> N >> W;
    for (int i = 0; i < N; ++i) std::cin >> weight.at(i) >> value.at(i);

    // DPループ
    for (int i = 0; i < N; ++i) {
        for (int sum_w = 0; sum_w <= W; ++sum_w) {
            // i番目の品物を選ぶとき
            if (sum_w - weight[i] >= 0) {
                chmax(dp.at(i + 1).at(sum_w), dp.at(i).at(sum_w - weight.at(i)) + value.at(i));
            }

            // i番目の品物を選ばないとき
            chmax(dp.at(i + 1).at(sum_w), dp.at(i).at(sum_w));
        }
    }

    // 答え
    std::cout << dp.at(N).at(W) << std::endl;

}

