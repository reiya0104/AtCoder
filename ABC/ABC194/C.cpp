/**
 *	author:  reiya0104
 *	created: 06.03.2021 21:31:26
 **/

#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001000;

int main() {
    int N;
    cin >> N;
    int A[N + 1];
    long long s[N + 1];
    s[0] = 0;
    long long S = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        S += A[i] * A[i];
        s[i] = s[i - 1] + A[i];
    }

    S *= (long long)(N - 1);

    // for (int i=0; i<=N;i++) {
    //     cout << "s[" << i << "] = " << s[i] << endl;
    // }

    long long T = 0;
    for (int i = 1; i <= N; ++i) {
        // int res1 = 0;
        // for (int j = i + 1; j <= N; ++j) {
        //     res1 += A[j];
        // }
        T += A[i] * (s[N] - s[i]);
    }
    cout << S - 2LL * T << endl;
}
