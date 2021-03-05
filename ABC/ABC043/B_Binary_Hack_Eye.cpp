/**
 *	author:  reiya0104
 *	created: 05.03.2021 15:44:11
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    vector<char> ans;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) == '0' || s.at(i) == '1') {
            ans.push_back(s.at(i));
        } else if (s.at(i) == 'B') {
            if (ans.size() != 0) {
                ans.pop_back();
            }
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans.at(i);
        if (i == ans.size() - 1) cout << endl;
    }
}
