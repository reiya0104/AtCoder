#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    using pii = pair<int, int>;
    vector<pii> data(N, make_pair(0, 0));
    for (pii &v: data) {
        cin >> v.second >> v.first;
    }
    sort(data.begin(), data.end());
    for (pii &v: data) {
        v = make_pair(v.second, v.first);
    }
    for (auto v: data) {
        cout << v.first << " " << v.second << endl;
    }


}
