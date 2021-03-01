#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> data(N+1);
    data.at(0) = {0, 0, 0};
    for (int i = 1; i <= N; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        data.at(i) = {t, x, y};
    }

    string ans = "Yes";
    for (int i = 1; i <= N; i++) {
        vector<int> vec_post = data.at(i);
        vector<int> vec_pre = data.at(i - 1);
        int dt = vec_post.at(0) - vec_pre.at(0);
        int dx = vec_post.at(1) - vec_pre.at(1);
        int dy = vec_post.at(2) - vec_pre.at(2);
        if (!((dt % 2 == (abs(dx) + abs(dy)) % 2) &&
              (abs(dx) + abs(dy) <= dt))) {
            ans = "No";
            break;
        }
    }
    cout << ans << endl;
}
