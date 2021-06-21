#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int a = 1900 * (M) + 100 * (N - M);
    int b = 1;
    for (int i = 0; i < M; ++i) b <<= 1;
    cout << a * b << endl;
}
