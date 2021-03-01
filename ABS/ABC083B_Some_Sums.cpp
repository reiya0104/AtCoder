#include <bits/stdc++.h>
using namespace std;

int digit_sum(int a) {
    int x = 0;
    while (a > 0) {
        x += a % 10;
        a /= 10;
    }
    return x;
}

int main() {
    int ans = 0;
    int N, A, B;
    cin >> N;
    cin >> A >> B;
    for (int i = 1; i <= N; i++) {
        int k = digit_sum(i);
        if (k >= A && k <= B) {
            ans += i;
        };
    }
    cout << ans << endl;
}
