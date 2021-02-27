#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    int Max = max(max(A, B), C);
    int Min = min(min(A, B), C);
    cout << Max - Min << endl;
}
