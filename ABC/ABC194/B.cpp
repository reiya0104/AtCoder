/**
 *	author:  reiya0104
 *	created: 06.03.2021 21:04:46
**/
#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001000;

int main() {
    int N;
    cin >> N;
    int A_min = INF, B_min = INF, AB_min = INF, A_min_i = INF, B_min_i = INF;
    vector<int> A(N), B(N);
    int i1, i2;
    for (int i=0; i < N; ++i) {
        cin >> A.at(i) >> B.at(i);

        if (AB_min > A.at(i) + B.at(i)) {
            AB_min = A.at(i) + B.at(i);
        }
        if (A_min > A.at(i)) {
            A_min = A.at(i);
            A_min_i = i;
        }
        if (B_min > B.at(i)) {
            B_min = B.at(i);
            B_min_i = i;
        }
    }

    int A_min1 = INF, B_min1 = INF;

    for (int i = 0; i < N; ++i) {
        // B_min1
        if (B_min1 > B.at(i) && i != A_min_i) {
            B_min1 = B.at(i);
        }
        // A_min1
        if (A_min1 > A.at(i) && i != B_min_i) {
            A_min1 = A.at(i);
        }
    }
    cout << min(min(max(A_min, B_min1), max(A_min1, B_min)), AB_min) << endl;


}
