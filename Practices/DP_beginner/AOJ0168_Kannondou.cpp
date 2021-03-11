/**
 *	author:  reiya0104
 *	created: 06.03.2021 14:15:00
**/

#include <iostream>
#include <vector>

int main() {
    // 入力
    int n[100];
    int N;
    for (int i=0; i < 100; ++i) {
        std::cin >> n[i];
        if (n[i] == 0) {
            N = i;
            break;
        }
    }

    // ループ
    for (int i=0; i<N; ++i) {
        std::vector<int> dp(n[i]+1, 0);

        dp[0] = 1;
        for (int j = 1; j <= n[i]; ++j) {
            dp[j] = dp[j - 1];
            if (j > 1) dp[j] += dp[j - 2];
            if (j > 2) dp[j] += dp[j - 3];
        }

        // 出力
        int day = dp[n[i]] / 10 + (dp[n[i]] % 10 != 0);
        std::cout << day / 365 + (day % 365 != 0) << std::endl;
    }


}
