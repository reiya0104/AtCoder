#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int res = 3;
    if (a == b || b == c || c == a) res--;
    if (a == b && b == c && c == a) res--;
    cout << res << endl;

}
