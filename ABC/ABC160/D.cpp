/**
 *	author:  reiya0104
 *	created: 21.04.2021 00:02:23
**/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;

int N, X, Y;

void solve(vector<vector<int>> &graph, int i, vector<int> &dist) {
    int res = 0;
    queue<int> que;
    dist.assign(N, -1);
    dist.at(i) = 0;
    que.push(i);
    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (auto next_v : graph.at(v)) {
            if (dist.at(next_v) != -1) continue;
            dist.at(next_v) = dist.at(v) + 1;
            que.push(next_v);
        }
    }
}

int main() {
    cin >> N >> X >> Y;

    // グラフ作成
    vector<vector<int>> graph(N);
    for (int i = 0; i < N - 1; ++i) {
        graph.at(i).push_back(i + 1);
        graph.at(i + 1).push_back(i);
    }
    graph.at(X - 1).push_back(Y - 1);
    graph.at(Y - 1).push_back(X - 1);

    for (int i = 0; i < N; ++i) {
        sort(graph.at(i).begin(), graph.at(i).end());
    }

    vector<int> res(N, 0);

    for (int i = 0; i < N - 1; ++i) {
        vector<int> dist(N);
        solve(graph, i, dist);

        for (int j = i + 1; j < N; ++j) {
            ++res.at(dist.at(j));
        }
    }

    for (int i = 1; i < N; ++i) {
        cout << res.at(i) << endl;
    }

}
