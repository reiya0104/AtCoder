#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;

int main() {
    string S;
    cin >> S;

    vector<string> A(8);

    int n = 3;
    bool exist = false;
    for (int bit = 0; bit < (1 << n); ++bit) {
        string s = {S.at(0)};
        int res = (int)(S.at(0) - '0');
        vector<int> T;
        for (int i = 0; i < n; ++i) {
            string s_i = {S.at(i + 1)};
            if (bit & (1 << i)) {
                T.push_back(i);
                s += ("+" + s_i);
                res += (int)(S.at(i + 1) - '0');
            } else {
                s += ("-" + s_i);
                res -= (int)(S.at(i + 1) - '0');
            }
        }
        if (res == 7) {
            exist = true;
            s += "=" + to_string(res);
            cout << s << endl;
            break;
        }
    }

    if (!exist) {
        cout << "No" << endl;
    }
}
