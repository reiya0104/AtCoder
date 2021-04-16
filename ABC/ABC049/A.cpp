/**
 *	author:  reiya0104
 *	created: 16.04.2021 00:23:15
**/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); ++i) {
        if (s.at(i) == ',') s.at(i) = ' ';
    }

    cout << s << endl;
}
