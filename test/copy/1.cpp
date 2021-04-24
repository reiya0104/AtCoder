/**
 *	author:  reiya0104
 *	created: 17.04.2021 13:56:53
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;

#define show_vec(vec)                          \
    do {                                       \
        cout << #vec " = {";                   \
        for (int i = 0; i < vec.size(); ++i) { \
            cout << vec.at(i);                 \
            if (i != vec.size() - 1)           \
                cout << " ";                   \
            else                               \
                cout << "}" << endl;           \
        }                                      \
    } while (0)

int main() {
    vector<int> vec1(4, 3);
    vector<int> vec2{1, 2, 3};
    show_vec(vec1);
    show_vec(vec2);

    vector<int> vec3(vec1);
    vector<int> vec4 = vec2;
    show_vec(vec3);
    show_vec(vec4);
    vec4.at(0) = 10;
    show_vec(vec2);
    show_vec(vec4);
}

#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001000;

int main() {
    int N;
    cin >> N;
    vector<int> W(N);
    for (int i = 0; i < N; ++i) cin >> W.at(i);

    vector<int> S(N + 1);
    S.at(0) = 0;
    for (int i = 0; i < N; ++i) S.at(i + 1) = S.at(i) + W.at(i);

    int res = INF;
    for (int i = 1; i < N; ++i) {
        int S1 = S.at(i);
        int S2 = S.at(N) - S1;
        int t = abs(S1 - S2);
        if (res > t) res = t;
    }

    cout << res << endl;
}

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    for (int i = 3; i <= (int)sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int nextPrime(int n) {
    if (n == 2) return 3;
    if (n & 1 == 0) --n;
    while (1) {
        n += 2;
        if (isPrime(n)) return n;
    }
    return 0;
}

int main() {
    int x;
    cin >> x;
    cout << nextPrime(x) << endl;
}
