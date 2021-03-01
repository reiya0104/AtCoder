#include <bits/stdc++.h>
using namespace std;

int main() {
    int A = 4;
    int j = 0;
    while (((A & 1) == 0) && (A > 0) && j < 10) {
        A >>= 1;
        j++;
    }
    cout << "j = " << j << endl;
}
