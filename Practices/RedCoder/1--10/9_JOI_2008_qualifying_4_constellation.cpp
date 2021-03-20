/**
 *	author:  reiya0104
 *	created: 18.03.2021 17:04:18
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using xy = pair<int, int>;
const int INF = 1001001000;

int main() {
    // 入力
    int m;
    cin >> m;
    assert(1 <= m && m <= 200);
    vector<xy> star(m);
    for (int i = 0; i < m; ++i) cin >> star.at(i).first >> star.at(i).second;
    int n;
    cin >> n;
    assert(1 <= n && n <= 1000);
    vector<xy> pic(n);
    for (int i = 0; i < n; ++i) cin >> pic.at(i).first >> pic.at(i).second;

    // star, picをそれぞれx座標を基準にソート
    sort(star.begin(), star.end());
    sort(pic.begin(), pic.end());

    // 200個の星の星座と1000個の星のデータの距離を全探索(200*1000=2*10^5通り)
    // disはi-1番目と同じ距離の星があったら追加する
    vector<vector<xy>> dis(m);
    // i = 0のとき
    for (int j = 0; j < n; ++j) {
        int delta_x = pic.at(j).first - star.at(0).first;
        int delta_y = pic.at(j).second - star.at(0).second;
        dis.at(0).push_back(make_pair(delta_x, delta_y));
    }
    // i > 0のとき 二分探索で探す
    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int delta_x = pic.at(j).first - star.at(i).first;
            int delta_y = pic.at(j).second - star.at(i).second;
            xy vec = make_pair(delta_x, delta_y);
            auto itr =
                lower_bound(dis.at(i - 1).begin(), dis.at(i - 1).end(), vec);
            if (itr != dis.at(i - 1).end() && *itr == vec)
                dis.at(i).push_back(vec);
        }
    }

    // 答え
    assert(dis.at(m - 1).size() > 0);
    cout << dis.at(m - 1).at(0).first << " " << dis.at(m - 1).at(0).second
         << endl;
}
