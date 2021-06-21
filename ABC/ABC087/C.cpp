#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(2, vector<int>(N));
    for (int i = 0; i < N; ++i) cin >> A.at(0).at(i);
    for (int i = 0; i < N; ++i) cin >> A.at(1).at(i);

    int res = 0;
    for (int i = 0; i < N; ++i) {
        int res0 = 0;
        for (int j = 0; j <= i; ++j) {
            res0 += A.at(0).at(j);
        }
        for (int j = i; j < N; ++j) {
            res0 += A.at(1).at(j);
        }
        if (res < res0) res = res0;
    }

    cout << res << endl;
}
