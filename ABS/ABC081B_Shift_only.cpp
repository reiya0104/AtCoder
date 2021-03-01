#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    int ans = 100000000;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;

        int j = 0;
        while (((A & 1) == 0) && (A > 0)) {
            A >>= 1;
            j++;
        }

        if (ans > j) {
            ans = j;
        }
        if (ans == 0) {
            break;
        }
    }
    cout << ans << endl;
}
