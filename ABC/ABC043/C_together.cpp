/**
 *	author:  reiya0104
 *	created: 05.03.2021 15:50:13
 **/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, sum = 0;
    cin >> N;
    vector<int> A;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.push_back(a);
        sum += a;
    }
    int k1, k2;
    k1 = sum / N;
    if (sum >= 0) {
        k2 = k1 + 1;
    } else {
        k2 = k1 - 1;
    }

    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < N; i++) {
        sum1 += (A.at(i) - k1) * (A.at(i) - k1);
        sum2 += (A.at(i) - k2) * (A.at(i) - k2);
    }
    cout << min(sum1, sum2) << endl;
}
