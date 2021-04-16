/**
 *	author:  reiya0104
 *	created: 05.04.2021 01:19:38
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;

int main() {
    string s;
    cin >> s;

    int count_p = 0;
    int count_g = 0;
    int count_win = 0;
    int count_lose = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s.at(i) == 'p') {
            if (count_p < count_g) {
                ++count_p;
            } else {
                ++count_g;
                ++count_lose;
            }
        } else if (s.at(i) == 'g') {
            if (count_p < count_g) {
                ++count_p;
                ++count_win;
            } else {
                ++count_g;
            }
        }
    }
    int res = count_win - count_lose;
    cout << res << endl;
}
