/**
 *	author:  reiya0104
 *	created: 27.03.2021 22:48:00
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;

using Graph = vector<vector<int>>;

int R, C;
pair<int, int> s;  // start
pair<int, int> g;  // goal
vector<vector<char>> c;

// for BFS;
vector<int> dist;
queue<int> que;

int width;
int height;

Graph graph;

int pair_to_v(int x, int y) { return (x - 1) + (y - 1) * width; }

int pair_to_v(pair<int, int> p) { return pair_to_v(p.first, p.second); }

pair<int, int> v_to_pair(int v) {
    return make_pair(v % width + 1, v / width + 1);
}

int main() {
    cin >> R >> C;
    cin >> s.first >> s.second;
    cin >> g.first >> g.second;
    c.assign(R, vector<char>(C));
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> c.at(i).at(j);
        }
    }
  	// cout << "aaa" << endl;
  	
  	/* for (int i = 1; i < R - 1; ++i) {
      for (int j = 1; j < C - 1; ++j) {
             cout << "(" << i << ", " << j << ") = " << "\"" << c.at(i).at(j) << "\"" << endl;
      }
    } */
  
    width = C - 2;
    height = R - 2;
  	// cout << "width = " << width << " height = " << height << endl;

    graph = vector<vector<int>>(width * height, vector<int>());

    for (int i = 1; i < R - 1; ++i) {
        for (int j = 1; j < C - 1; ++j) {
            vector<int> nvec;
          	// cout << "pair_to_v(" << j << ", " << i << ") = " << pair_to_v(j, i) << endl;
            if (c.at(i).at(j) == '.') {
                // Left
                if (c.at(i).at(j - 1) == '.') {
                  	// cout << "pair_to_v(" << j << " - 1, " << i << ") = " << pair_to_v(j - 1, i) << endl;
                    nvec.push_back(pair_to_v(j - 1, i));
                }
                // Up
                if (c.at(i - 1).at(j) == '.') {
                  	// cout << "pair_to_v(" << j << ", " << i << " - 1) = " << pair_to_v(j, i - 1) << endl;
                    nvec.push_back(pair_to_v(j, i - 1));
                }
                // Left
                if (c.at(i).at(j + 1) == '.') {
                  	// cout << "pair_to_v(" << j << " + 1, " << i << ") = " << pair_to_v(j + 1, i) << endl;
                    nvec.push_back(pair_to_v(j + 1, i));
                }
                // Down
                if (c.at(i + 1).at(j) == '.') {
                  	// cout << "pair_to_v(" << j << ", " << i << " + 1) = " << pair_to_v(j, i + 1) << endl;
                    nvec.push_back(pair_to_v(j, i + 1));
                }
            }
            
            graph.at(pair_to_v(j, i)) = nvec;
        }
    }

    dist.assign(width * height, -1);
    que = queue<int>();
    dist.at(pair_to_v(s.second - 1, s.first - 1)) = 0;
    que.push(pair_to_v(s.second - 1, s.first - 1));

    // BFS開始
  	// cout << "pair_to_v(s.first - 1, s.second - 1) = " << pair_to_v(s.first - 1, s.second - 1) << endl;

    int v;
    while (!que.empty()) {
        v = que.front();
        que.pop();

        for (int nv : graph.at(v)) {
            if (dist.at(nv) != -1) continue;

            dist.at(nv) = dist.at(v) + 1;
            que.push(nv);
        }
    }
  
  	/* cout << "graph" << endl;
  	for (int i = 0; i < width * height; ++i) {
      	cout << i << ": ";
      	for (int j = 0; j < graph.at(i).size(); ++j) {
          cout << graph.at(i).at(j);
          if (j != graph.at(i).size() - 1) {
            cout << ", ";
          }
        }
        cout << endl;
    }
  
  	for (int i = 0; i < width * height; ++i) {
      	cout << i << ": " << dist.at(i) << endl;
    } */

    int res = dist.at(pair_to_v(g.second - 1, g.first - 1));
    cout << res << endl;
}
