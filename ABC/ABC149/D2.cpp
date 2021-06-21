#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;

int N, K;
int R, S, P;
string T;

vector<string> t_div, w_div;

ll solve(string s) {
    ll res = 0;
    res += count(s.begin(), s.end(), 'r') * R;
    res += count(s.begin(), s.end(), 's') * S;
    res += count(s.begin(), s.end(), 'p') * P;

    int i = 0;
    while (i < (int)s.size()) {
        int j = 0;
        while ((i + j + 1 < (int)s.size()) &&
               (s.at(i + j) == s.at(i + j + 1))) {
            ++j;
        }
        ++j;
        int A = (s.at(i) == 'r') ? R : ((s.at(i) == 's') ? S : P);
        res -= (j / 2) * A;
        i += j;
    }

    return res;
}

int main() {
    cin >> N >> K >> R >> S >> P >> T;
    t_div.assign(K, "");
    w_div.assign(K, "");
    for (int i = 0; i < N; ++i) {
        t_div.at(i % K) += T.at(i);
    }

    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < (int)t_div.at(i).size(); ++j) {
            string s = (t_div.at(i).at(j) == 'r')
                           ? "p"
                           : ((t_div.at(i).at(j) == 's') ? "r" : "s");
            w_div.at(i) += s;
        }
    }

    ll res = 0;
    for (int i = 0; i < K; ++i) {
        res += solve(w_div.at(i));
    }
    cout << res << endl;
}
