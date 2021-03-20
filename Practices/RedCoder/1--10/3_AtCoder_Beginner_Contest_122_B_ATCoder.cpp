/**
 *	author:  reiya0104
 *	created: 15.03.2021 09:34:33
**/

#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001000;

bool isACGT(char x) {
    return (x == 'A' || x == 'C' || x == 'G' || x == 'T');
}

int main() {
    string S;
    cin >> S;
    int res = 0;
    for (int i = 0; i < S.size(); ++i) {
        if (isACGT(S.at(i))) {
            int res_s = 1;
            for (int j = i + 1; j < S.size(); ++j) {
                if (isACGT(S.at(j))) ++res_s;
                else break;
            }
            if (res < res_s) res = res_s;
        }
    }
    cout << res << endl;
}
