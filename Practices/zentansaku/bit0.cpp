#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001000;

int main() {
    int n = 5;

    for (int bit = 0; bit < (1 << n); ++bit) {
        vector<int> S;
        for (int i = 0; i < n; ++i) {
            // iがbitに入っているか
            if (bit & (1 << i)) {
                S.push_back(i);
            }
        }
        // bitの入っている集合
        cout << bit << " : {";
        for (int i = 0; i < (int)S.size(); ++i) {
            cout << S.at(i);
            if (i != (int)S.size() - 1) {
                cout << " ";
            }
        }
        cout << "}" << endl;
    }
}
