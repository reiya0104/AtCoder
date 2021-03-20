/**
 *	author:  reiya0104
 *	created: 19.03.2021 15:54:34
 **/

#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;

bool isAlive(pii &Q, vector<vector<int>> &mass) {
    return (bool)(mass.at(Q.first).at(Q.second));
}

// Qがおかれたときのmassの変化
bool ope(pii &Q, vector<vector<int>> &mass) {
    if (mass.at(Q.first).at(Q.second) == 0) return false;

    // 行
    for (int i = 0; i < 8; ++i) mass.at(Q.first).at(i) = 0;
    // 列
    for (int i = 0; i < 8; ++i) mass.at(i).at(Q.second) = 0;
    // 斜め
    for (int i = 0; i < 8; ++i) {
        if (Q.first - i >= 0 && Q.second - i >= 0)
            mass.at(Q.first - i).at(Q.second - i) = 0;
        if (Q.first + i < 8 && Q.second + i < 8)
            mass.at(Q.first + i).at(Q.second + i) = 0;
        if (Q.first - i >= 0 && Q.second + i < 8)
            mass.at(Q.first - i).at(Q.second + i) = 0;
        if (Q.first + i < 8 && Q.second - i >= 0)
            mass.at(Q.first + i).at(Q.second - i) = 0;
    }

    mass.at(Q.first).at(Q.second) = 2;
    return true;
}

void show(vector<vector<int>> &mass) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (mass.at(i).at(j) == 0)
                cout << ".";
            else if (mass.at(i).at(j) == 1)
                cout << "o";
            else if (mass.at(i).at(j) == 2)
                cout << "Q";

            if (j != 7) {
                // cout << " ";
            } else {
                cout << endl;
            }
        }
    }
}

int main() {
    // 入力
    int k;
    cin >> k;
    vector<pii> rc(k);
    vector<bool> r_alive(8, true);
    vector<bool> c_alive(8, true);
    for (int i = 0; i < k; ++i) {
        cin >> rc.at(i).first >> rc.at(i).second;
        assert(0 <= rc.at(i).first && rc.at(i).first <= 7 &&
               0 <= rc.at(i).second && rc.at(i).second <= 7);
        r_alive.at(rc.at(i).first) = false;
        c_alive.at(rc.at(i).second) = false;
    };

    vector<vector<int>> mass(8, vector<int>(8, 1));

    for (int i = 0; i < k; ++i) {
        ope(rc.at(i), mass);
    }

    vector<vector<int>> Mass = mass;
    // show(Mass);

    vector<int> r_perm;
    vector<int> c_perm;
    for (int i = 0; i < 8; ++i) {
        if (r_alive.at(i)) r_perm.push_back(i);
        if (c_alive.at(i)) c_perm.push_back(i);
    }
    sort(r_perm.begin(), r_perm.end());
    sort(c_perm.begin(), c_perm.end());

    do {
        mass = Mass;
        bool exist = true;
        for (int i = 0; i < r_perm.size(); ++i) {
            pii Q = make_pair(r_perm.at(i), c_perm.at(i));
            if (!(ope(Q, mass))) {
                exist = false;
                break;
            }
        }
        if (exist) break;
    } while (next_permutation(c_perm.begin(), c_perm.end()));

    show(mass);
}
