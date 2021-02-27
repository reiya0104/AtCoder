#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> data(5, 0);
    bool ans = false;
    for (int i=0; i < data.size(); i++) {
        cin >> data.at(i);
        if (i > 0) {
            if (data.at(i) - data.at(i-1) == 0) {
                ans = true;
                break;
            }
        }
    }

    if (ans) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
