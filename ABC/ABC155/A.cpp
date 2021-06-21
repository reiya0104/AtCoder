/**
 *	author:  reiya0104
 *	created: 10.05.2021 00:09:48
 **/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    bool res = false;
    if ((A == B && A != C) || (B == C && A != C) || (A == C && B != C))
        res = true;

    if (res)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
