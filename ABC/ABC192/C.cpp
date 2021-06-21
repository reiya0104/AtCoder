#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> to_vector(int n) {
    vector<int> res;
    int i = 0;
    while (n) {
        res.push_back(n % 10);
        n /= 10;
        ++i;
    }
    return res;
}

int to_int(vector<int> vec) {
    int res = 0;
    int N = vec.size();
    for (int i = 0; i < N; ++i) {
        res *= 10;
        res += vec.at(N - i - 1);
    }
    return res;
}

int func(int n) {
    vector<int> digit = to_vector(n);

    sort(digit.begin(), digit.end());
    int g1 = to_int(digit);
    reverse(digit.begin(), digit.end());
    int g2 = to_int(digit);

    return g1 - g2;
}

int solve(int n, int k) {
    for (int i = 0; i < k; ++i) {
        n = func(n);
    }
    return n;
}

int main() {
    int N, K;
    cin >> N >> K;

    cout << solve(N, K) << endl;
}
