/**
 *	author:  reiya0104
 *	created: 20.03.2021 13:58:45
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;

#define show_vec(vec)                          \
    do {                                       \
        cout << #vec " = {";                   \
        for (int i = 0; i < vec.size(); ++i) { \
            cout << vec.at(i);                 \
            if (i != vec.size() - 1)           \
                cout << " ";                   \
            else                               \
                cout << "}" << endl;           \
        }                                      \
    } while (0)

int main() {
    vector<int> a = {1, 2, 3};
    show_vec(a);
}
