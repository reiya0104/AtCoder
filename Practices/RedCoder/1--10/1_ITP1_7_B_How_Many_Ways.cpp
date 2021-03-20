/**
 *	author:  reiya0104
 *	created: 15.03.2021 08:39:32
 **/

#include <algorithm>
#include <cassert>
#include <iostream>
using namespace std;

int func(int n, int x) {
    int res = 0;
    for (int i = max(1, x - 2 * n + 1); i < x / 3; ++i) {
        int k = ((x - i - 1) / 2) - max(i + 1, x - n - i) + 1;
        // cout << "i = " << i << ", res += " << k << endl;
        res += k;
    }
    return res;
}

int main() {
    // 入力
    int n, x;
    cin >> n >> x;
    while (n != 0 || x != 0) {
        assert(3 <= n && n <= 100 && 0 <= x && x <= 300);
        cout << func(n, x) << endl;
        cin >> n >> x;
    }
}
