// /**
//  *	author:  reiya0104
//  *	created: 26.04.2021 22:55:29
//  **/

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// ll GCD(ll a, ll b) {
//     while (b) {
//         ll OldA = a;
//         a = b;
//         b = OldA % b;
//     }
//     return a;
// }

// ll LCM(ll a, ll b) { return (a / GCD(a, b)) * b; }

// int main() {
//     // ll a = 1, b = 2;
//     // cout << LCM(a, b) << endl;
//     // return 0;
//     int N;
//     ll M;
//     cin >> N >> M;
//     vector<ll> a(N);
//     for (int i = 0; i < N; ++i) cin >> a.at(i);

//     ll L = 2;
//     for (int i = 0; i < N; ++i) L = LCM(L, a.at(i));

//     ll L2 = L / 2;
//     ll res;
//     if (M < L2)
//         res = 0;
//     else
//         res = (M - L2) / L + 1;
//     cout << res << endl;
// }

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;

int main() {
    int K, A, B;
    cin >> K >> A >> B;
    int k_a = A / K;
    int k_b = B / K;
    bool res = false;
    if (k_b - k_a > 0)
        res = true;
    else {
        if ((k_a * K >= A && k_a * K <= B) ||
            ((k_a + 1) * K >= A && (k_a + 1) * K <= B))
            res = true;
    }

    if (res) cout << "OK" << endl;
    else cout << "NG" << endl;
}
