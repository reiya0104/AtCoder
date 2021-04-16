/**
 *	author:  reiya0104
 *	created: 02.04.2021 18:35:33
 **/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1001001000;
#define MAX 201000
const int MOD = 2019;
string S;

vector<int> ModDecData(MAX);
vector<int> ModData(MAX);
vector<ll> counter(MOD);


void setModDecData() {
    ModData.assign(S.size() + 1, -1);
    int k = 1;
    for (int i = 0; i <= S.size(); ++i) {
        ModDecData.at(i) = k;
        k = (k * 10) % MOD;
    }
}

void setModData() {
    ModData.assign(S.size() + 1, -1);
    ModData.at(0) = 0;
    for (int i = 0; i < S.size(); ++i) {
        int num = (int)S.at(S.size() - i - 1) - (int)'0';
        ModData.at(i + 1) = (ModData.at(i) + num * ModDecData.at(i)) % MOD;
        // printf("ModData.at(%d) = (ModData.at(%d) + S.at(%d) * ModDecMul(%d)) % MOD = %d\n", i + 1, i, S.size() - i - 1, i, ModData.at(i + 1));
    }
}

void setCounter() {
    for (int i = 0; i < MOD; ++i) {
        counter.at(i) = count(ModData.cbegin(), ModData.cend(), i);
    }
}

int main() {
    cin >> S;

    setModDecData();

    setModData();

    setCounter();

    ll res = 0;
    for (int i = 0; i < MOD; ++i) {
        res += (counter.at(i) * (counter.at(i) - 1LL)) / 2LL;
    }
    cout << res << endl;

    // cout << "S.size = " << S.size() << endl;

    // cout << "ModData = " << endl;
    // for (int i = 0; i < ModData.size(); ++i) {
    //     cout << i << ": " << ModData.at(i) << endl;
    // }

}
