#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;
#define MAX 100000

int N, M, Q;

int rec(int index, vector<int> &vec, int &count, vector<vector<int>> &data) {
    if (index == 0) {
        data = vector<vector<int>>(MAX, vector<int>(N, 0));
        vec = vector<int>(N, 0);
        for (int i = 1; i <= M; ++i) {
            vec.at(index) = i;
            rec(index + 1, vec, count, data);
        }
    } else if (index != N - 1) {
        for (int i = vec.at(index - 1); i <= M; ++i) {
            vec.at(index) = i;
            rec(index + 1, vec, count, data);
        }
    } else {
        for (int i = vec.at(index - 1); i <= M; ++i) {
            vec.at(index) = i;
            data.at(count) = vec;
            ++count;
        }
    }
    return count;
}

int main() {
    cin >> N >> M >> Q;
    vector<vector<int>> D(Q, vector<int>(4, 0));
    for (int i = 0; i < Q; ++i) {
        cin >> D.at(i).at(0) >> D.at(i).at(1) >> D.at(i).at(2) >> D.at(i).at(3);
    }

    vector<int> vec(N, 0);
    vector<vector<int>> data(MAX, vector<int>(N, 0));
    int count = 0;
    int K = rec(0, vec, count, data);

    // for (int i = 0; i < K; ++i) {
    //     cout << i << ": (";
    //     for (int j = 0; j < N; ++j) {
    //         cout << data.at(i).at(j);
    //         if (j != N - 1) cout << ", ";
    //         else cout << ")" << endl;
    //     }
    // }

    ll res = 0;
    for (int i = 0; i < K; ++i) {
        ll res0 = 0;
        for (int j = 0; j < Q; ++j) {
            if (data.at(i).at(D.at(j).at(1) - 1) - data.at(i).at(D.at(j).at(0) - 1) ==
                D.at(j).at(2))
                res0 += D.at(j).at(3);
        }
        if (res < res0) res = res0;
    }
    cout << res << endl;
}
