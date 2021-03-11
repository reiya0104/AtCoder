/**
 *	author:  reiya0104
 *	created: 10.03.2021 12:54:20
 **/

#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001000;

int main() {
    vector<string> S(3);
    cin >> S.at(0) >> S.at(1) >> S.at(2);
    int i = 0;
    while (true) {
        if (!(S.at(i).empty())) {
            int j = S.at(i).at(0) - 'a';
            S.at(i) = S.at(i).erase(0, 1);
            i = j;
            continue;
        }
        break;
    }
    char res;
    if (i == 0) res = 'A';
    if (i == 1) res = 'B';
    if (i == 2) res = 'C';
    cout << res << endl;
}
