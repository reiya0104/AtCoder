/**
 *	author:  reiya0104
 *	created: 31.03.2021 15:56:12
**/

#include <bits/stdc++.h>
using namespace std;
int main() {
    set<string> S;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        S.insert(s);
    }
    cout << S.size() << endl;
}
