/**
 *	author:  reiya0104
 *	created: 05.03.2021 16:45:54
 **/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    bool nothing = true;
    cin >> s;
    map<char, int> data;
    int max = -1;
    for (int i = 0; i < s.size(); i++) {
        if (i > 0) {
            if (i > 1) {
                if (s.at(i - 2) == s.at(i)) {
                    cout << i - 1 << " " << i + 1 << endl;
                    nothing = false;
                    break;
                }
            }
            if (s.at(i - 1) == s.at(i)) {
                cout << i << " " << i + 1 << endl;
                nothing = false;
                break;
            }
        }
    }

    if (nothing) {
        cout << "-1 -1" << endl;
    }
}
