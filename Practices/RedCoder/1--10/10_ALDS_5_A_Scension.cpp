/**
 *	author:  reiya0104
 *	created: 18.03.2021 18:12:21
 **/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 入力
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) cin >> A.at(i);
    int q;
    cin >> q;
    vector<int> m(q);
    for (int i = 0; i < q; ++i) cin >> m.at(i);

    // 答え用のvector
    vector<bool> res(q, false);

    // bit全探索
    for (int bit = 0; bit < (1 << n); ++bit) {
        // 要素を足す
        int ans = 0;
        for (int i = 0; i < n; ++i)
            if (bit & (1 << i)) ans += A.at(i);

        for (int i = 0; i < q; ++i) {
            if (ans == m.at(i)) res.at(i) = true;
        }
    }

    // 答え
    for (int i = 0; i < q; ++i) {
        if (res.at(i)) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
