/**
 *	author:  reiya0104
 *	created: 20.03.2021 11:35:56
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;
#define show_vec_int(vec)                      \
    do {                                       \
        cout << "#vec = {";                    \
        for (int i = 0; i < vec.size(); ++i) { \
            cout << vec.at(i);                 \
            if (i != vec.size() - 1)           \
                cout << " ";                   \
            else                               \
                cout << "}" << endl;           \
        }                                      \
    } while (0)

#define show_vec_int(vec)                      \
    do {                                       \
        cout << "#vec = {";                    \
        for (int i = 0; i < vec.size(); ++i) { \
            cout << vec.at(i);                 \
            if (i != vec.size() - 1)           \
                cout << " ";                   \
            else                               \
                cout << "}" << endl;           \
        }                                      \
    } while (0)

bool isOK(vector<int> &vec, int &index, int &key) {
    if (vec.at(index) >= key)
        return true;
    else
        return false;
}

int binary_search(vector<int> &vec, int key) {
    int ng = -1;
    int ok = vec.size();
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (isOK(vec, mid, key))
            ok = mid;
        else
            ng = mid;
    }
    return ok;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N);
    for (int i = 0; i < N; ++i) cin >> A.at(i);
    for (int i = 0; i < N; ++i) cin >> B.at(i);
    for (int i = 0; i < N; ++i) cin >> C.at(i);

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    // SはBiより真に大きいものの総和
    vector<int> Bi(N), Ci(N);
    vector<ll> S(N + 1);
    for (int i = 0; i < N; ++i) Bi.at(i) = binary_search(B, A.at(i) + 1);
    for (int i = 0; i < N; ++i) Ci.at(i) = binary_search(C, B.at(i) + 1);
    // cout << "Bi = ";
    // show_vec_int(Bi);
    // cout << "Ci = ";
    // show_vec_int(Ci);

    S.at(N) = 0;
    for (int i = N - 1; i > -1; --i) {
        S.at(i) = S.at(i + 1) + (N - Ci.at(i));
    }

    // cout << "S = ";
    // show_vec_int(S);

    ll res = 0;
    for (int i = 0; i < N; ++i) {
        res += S.at(Bi.at(i));
    }

    cout << res << endl;
}
