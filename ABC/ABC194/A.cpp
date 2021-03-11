#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001000;

int main() {
    int A, B;
    cin >> A >> B;

    int res;

    if (A + B >= 15 && B >= 8) {
        res = 1;
    }
    else if (A + B >= 10 && B >= 3) {
        res = 2;
    }
    else if (A + B >= 3) {
        res = 3;
    }
    else res = 4;

    cout << res << endl;
}
