#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    string ans = "NO";
    if (A >= 5 && A <= 7 && B >= 5 && B <= 7 && C >= 5 && C <= 7) {
        if (A * B * C == 175) ans = "YES";
    }
    cout << ans << endl;
}
