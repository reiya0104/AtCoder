/**
 *	author:  reiya0104
 *	created: 26.03.2021 22:30:36
**/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;

int N, Q;
string S;
vector<pair<int, int>> LR;

void solve(string &s, vector<int> &vec) {
    for (int i = 0; i < s.size(); ++i) {
        if (s.at(i) == 'A' && s.at(i + 1) == 'C') {
            vec.push_back(i);
        }
        if (i + 1 == s.size() - 1) break;
    }
}

int main() {
    cin >> N >> Q >> S;
    LR.assign(Q, make_pair(0, 0));
    for (int i = 0; i < Q; ++i) cin >> LR.at(i).first >> LR.at(i).second;

    vector<int> vec;
    solve(S, vec);

    for (int i = 0; i < Q; ++i) {
        auto itr1 = lower_bound(vec.begin(), vec.end(), LR.at(i).first - 1);
        auto itr2 = lower_bound(vec.begin(), vec.end(), LR.at(i).second - 1);
        cout << itr2 - itr1 << endl;
    }
}
