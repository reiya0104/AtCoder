/**
 *	author:  reiya0104
 *	created: 15.03.2021 08:24:37
**/



#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001000;


int divisor(int N) {
    assert(N >= 1 && N <= 200);
    int res = 0;
    for (int i = 1; i <= N; ++i) {
        if (N % i == 0) ++res;
    }
    return res;
}

int main() {
    int N;
    cin >> N;
    int res = 0;
    for (int i = 1; i <= N; i += 2) {
        if (divisor(i) == 8) {
            ++res;
        }
    }
    cout << res << endl;
}
