/**
 *	author:  reiya0104
 *	created: 12.05.2021 11:59:04
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; ++i) cin >> S.at(i);

    map<string, int> data;
    for (int i = 0; i < N; ++i) {
        if (!data.count(S.at(i))) {
            data[S.at(i)] = 1;
        } else
            ++data[S.at(i)];
    }

    vector<pair<int, string>> res;
    for (auto itr = data.begin(); itr != data.end(); ++itr) {
        res.push_back(make_pair((*itr).second, (*itr).first));
    }

    sort(res.begin(), res.end());

    int count_max = res.at((int)res.size() - 1).first;
    for (int i = 0; i < res.size(); ++i) {
        if (res.at(i).first == count_max) cout << res.at(i).second << endl;
    }
}
