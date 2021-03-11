#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001000;

int main() {
    int N, K, X, Y;
    cin >> N >> K >> X >> Y;
    
    int res = 0;

    for (int i = 0; i < N; ++i) {
        if (i < K) res += X;
        else res += Y;
    }

    cout << res << endl;
}
