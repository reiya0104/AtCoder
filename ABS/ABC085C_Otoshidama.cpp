#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Y;
    cin >> N;
    cin >> Y;
    Y /= 1000;
    int Z = Y - N;
    int ans = true;
    for (int x = 0; ((x <= N) && (x <= Z / 9)); x++) {
        for (int y = 0; ((y <= N - x) && (y <= (Z - 9 * x) / 4)); y++) {
            if (9 * x + 4 * y == Z) {
                cout << x << " " << y << " " << N - x - y << endl;
                ans = false;
                goto OUT;
            }
        }
    }
OUT:
    if (ans) {
        cout << "-1 -1 -1" << endl;
    }
}
