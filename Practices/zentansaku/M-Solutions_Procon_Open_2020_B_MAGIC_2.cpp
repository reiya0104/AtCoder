/**
 *	author:  reiya0104
 *	created: 17.03.2021 15:21:15
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001000;

int main() {
    int A, B, C;
    int K;
    cin >> A >> B >> C >> K;
    bool exist = false;

    // 木構造
    // 親要素n -> 子要素3*n+1,3*n+2,3*n+3
    // 子要素n -> 親要素floor((3*n-1)/3)
    vector<vector<int>> rgb(3280, vector<int>(3));
    rgb.at(0).at(0) = A;
    rgb.at(0).at(1) = B;
    rgb.at(0).at(2) = C;

    int p = 1;  // i段数におけるの要素の個数
    int q = 1;  // i段目の先頭項
    // i段目の要素を求める
    for (int i = 1; i <= K; ++i) {
        p *= 3;
        for (int j = 0; j < p; ++j) {
            rgb.at(q + j) = rgb.at((q + j - 1) / 3);
            rgb.at(q + j).at(j % 3) *= 2;
            if (rgb.at(q + j).at(1) > rgb.at(q + j).at(0) &&
                rgb.at(q + j).at(2) > rgb.at(q + j).at(1)) {
                exist = true;
                goto end;
            }
        }
        q += p;
    }
end:;
    if (exist) cout << "Yes" << endl;
    else cout << "No" << endl;

    // p = 1;
    // q = 1;
    // for (int i = 1; i <= K; ++i) {
    //     p *= 3;
    //     for (int j = 0; j < p; ++j) {
    //         // rgb.at(q + j) = rgb.at((q + j - 1) / 3);
    //         printf("i = %4d: %d段 %3d個目 (%4d, %4d, %4d)\n", q + j, i, j,
    //                rgb.at(q + j).at(0), rgb.at(q + j).at(1),
    //                rgb.at(q + j).at(2));
    //     }
    //     cout << endl;
    //     q += p;
    // }
}
