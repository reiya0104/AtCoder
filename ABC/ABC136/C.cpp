#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> H(N);
    for (int i = 0; i < N; ++i) cin >> H.at(i);

    bool res = true;
    for (int i = 0; i < N - 1; ++i) {
        if (H.at(i) - H.at(i + 1) > 1) res = false;
        else if (i < N - 2) {
            if (H.at(i) - H.at(i + 1) > 0 && H.at(i + 1) - H.at(i + 2) > 0) res = false;
        }
    }

    if (res)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
