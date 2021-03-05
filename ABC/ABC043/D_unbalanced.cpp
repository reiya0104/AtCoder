/**
 *	author:  reiya0104
 *	created: 05.03.2021 16:15:27
 **/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    bool nothing = true;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        map<char, int> data;
        int max = -1;
        for (int j = i; j < s.size(); j++) {
            if (data.count(s.at(j))) {
                data.at(s.at(j))++;
            } else {
                data[s.at(j)] = 1;
            }
            if (max < data.at(s.at(j))) {
                // cout << "max = " << max << " --> ";
                max = data.at(s.at(j));
                // cout << max << " = data.at(" << s.at(j) << ")" << endl;
            }
            int size = j - i + 1;
            if (size > 1 && max * 2 > size) {
                nothing = false;
                // cout << "s.at(" << i << ") = " << s.at(i) << endl;
                // cout << "s.at(" << j << ") = " << s.at(j) << endl;
                // cout << "size = " << size << ", max = " << max << endl;
                // for (auto v : data) {
                //     cout << v.first << " => " << v.second << endl;
                // }
                cout << i + 1 << " " << j + 1 << endl;
                break;
            }
        }
        if (!nothing) {
            break;
        }
    }
    if (nothing) {
        cout << "-1 -1" << endl;
    }
}
