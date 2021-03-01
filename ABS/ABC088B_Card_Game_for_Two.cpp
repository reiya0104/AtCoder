#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> vec;
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        vec.push_back(A);
    }
    sort(vec.begin(), vec.end());
    // for (auto v : vec) {
    //     cout << v;
    // }
    // cout << endl;

    int a = 0;
    int b = 0;
    for (int i = N - 1; i > -1; i -= 2) {
        a += vec.at(i);
        if (i != 0) b += vec.at(i - 1);
    }
    cout << a - b << endl;
}
