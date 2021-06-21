#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;

int H, W;
vector<vector<int>> S;
int B;

int to_index(int i, int j) { return W * i + j; }
int to_index(pair<int, int> point) {
    return to_index(point.first, point.second);
}

pair<int, int> to_point(int i) { return make_pair(i / W, i % W); }

vector<vector<int>> graph;

void set_graph() {
    graph.resize(H * W);
    for (int i = 0; i < H * W; ++i) {
        pair<int, int> p = to_point(i);
        int y = p.first;
        int x = p.second;
        if (S.at(y).at(x) == 1) continue;
        if (y > 0) {
            if (S.at(y - 1).at(x) == 0)
                graph.at(i).push_back(to_index(y - 1, x));
        }
        if (x > 0) {
            if (S.at(y).at(x - 1) == 0)
                graph.at(i).push_back(to_index(y, x - 1));
        }
        if (x < W - 1) {
            if (S.at(y).at(x + 1) == 0)
                graph.at(i).push_back(to_index(y, x + 1));
        }
        if (y < H - 1) {
            if (S.at(y + 1).at(x) == 0)
                graph.at(i).push_back(to_index(y + 1, x));
        }
    }
}

vector<int> dist;
queue<int> que;

void BSF() {
    pair<int, int> start = make_pair(0, 0);

    dist.assign(H * W, -1);
    dist.at(to_index(start)) = 0;
    que.push(to_index(start));

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        pair<int, int> p = to_point(v);

        for (auto next_v : graph.at(v)) {
            if (dist.at(next_v) != -1) continue;
            dist.at(next_v) = dist.at(v) + 1;
            que.push(next_v);
        }
    }
}

int solve() {
    return (dist.at(H * W - 1) != -1) ? (H * W - dist.at(H * W - 1) - B - 1)
                                      : -1;
}

void show() {
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cout << S.at(i).at(j);
        }
        cout << endl;
    }
}

void show_graph() {
    for (int i = 0; i < H * W; ++i) {
        pair<int, int> p = to_point(i);
        cout << "(y, x) = (" << p.first << ", " << p.second << ") = {";
        for (int j = 0; j < (int)graph.at(i).size(); ++j) {
            pair<int, int> p_j = to_point(graph.at(i).at(j));
            cout << "(" << p_j.first << ", " << p_j.second << ")";
            if (j != (int)graph.at(i).size() - 1) cout << ", ";
        }
        cout << "}" << endl;
    }
}

void show_dist() {
    for (int i = 0; i < H * W; ++i) {
        pair<int, int> p = to_point(i);
        cout << "(y, x) = (" << p.first << ", " << p.second
             << ") = " << dist.at(i) << endl;
    }
}

int main() {
    cin >> H >> W;
    S.resize(H);
    B = 0;
    for (int i = 0; i < H; ++i) {
        string s;
        cin >> s;
        S.at(i).resize(W);
        for (int j = 0; j < W; ++j) {
            if (s.at(j) == '.')
                S.at(i).at(j) = 0;
            else if (s.at(j) == '#') {
                S.at(i).at(j) = 1;
                ++B;
            }
        }
    }

    set_graph();
    BSF();
    cout << solve() << endl;
}
