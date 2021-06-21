#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;

int W, H;
vector<vector<int>> P;

vector<vector<int>> graph;
void set_graph();

vector<int> dist;
queue<int> que;

void BSF() {
    dist.assign((int)graph.size(), -1);

    dist.at(0) = 0;
    que.push(0);

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

void set_graph() {
    graph.assign((H + 2) * (W + 2), vector<int>());
    for (int i = 0; i <= H + 1; ++i) {
        for (int j = 0; j <= W + 1; ++j) {
            if (P.at(i).at(j) != 0) continue;
            int index = i * (W + 2) + j;

            if (i > 0) {
                if (P.at(i - 1).at(j) == 0)
                    graph.at(index).push_back(index - (W + 2));

                if (i % 2 == 0) {
                    if (j > 0 && P.at(i - 1).at(j - 1) == 0)
                        graph.at(index).push_back(index - (W + 2) - 1);
                } else {
                    if (j < W + 1 && P.at(i - 1).at(j + 1) == 0)
                        graph.at(index).push_back(index - (W + 2) + 1);
                }
            }

            if (j > 0)
                if (P.at(i).at(j - 1) == 0)
                    graph.at(index).push_back(index - 1);
            if (j < W + 1)
                if (P.at(i).at(j + 1) == 0)
                    graph.at(index).push_back(index + 1);

            if (i < H + 1) {
                if (P.at(i + 1).at(j) == 0)
                    graph.at(index).push_back(index + (W + 2));

                if (i % 2 == 0) {
                    if (j > 0 && P.at(i + 1).at(j - 1) == 0)
                        graph.at(index).push_back(index + (W + 2) - 1);
                } else {
                    if (j < W + 1 && P.at(i + 1).at(j + 1) == 0)
                        graph.at(index).push_back(index + (W + 2) + 1);
                }
            }
        }
    }
}

int empty_count(int index) {
    if (dist.at(index) != -1) return 0;

    int res = 0;

    int i = index / (W + 2);
    int j = index % (W + 2);

    if (i > 0) {
        if (dist.at(index - (W + 2)) != -1) ++res;

        if (i % 2 == 0) {
            if (j > 0 && dist.at(index - (W + 2) - 1) != -1) ++res;
        } else {
            if (j < W + 1 && dist.at(index - (W + 2) + 1) != -1) ++res;
        }
    }

    if (j > 0)
        if (dist.at(index - 1) != -1) ++res;
    if (j < W + 1)
        if (dist.at(index + 1) != -1) ++res;

    if (i < H + 1) {
        if (dist.at(index + (W + 2)) != -1) ++res;

        if (i % 2 == 0) {
            if (j > 0 && dist.at(index + (W + 2) - 1) != -1) ++res;
        } else {
            if (j < W + 1 && dist.at(index + (W + 2) + 1) != -1) ++res;
        }
    }

    return res;
}

int main() {
    cin >> W >> H;
    P.resize(H + 2);
    P.at(0).assign(W + 2, 0);
    P.at(H + 1).assign(W + 2, 0);
    for (int i = 1; i <= H; ++i) {
        P.at(i).assign(W + 2, 0);
        for (int j = 1; j <= W; ++j) {
            cin >> P.at(i).at(j);
        }
    }

    set_graph();
    BSF();

    int res = 0;

    for (int i = 0; i < (int)graph.size(); ++i) {
        res += empty_count(i);
    }

    cout << res << endl;
}
