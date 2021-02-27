#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 1;
    string S;
    getline(cin, S);

    int s = S.size();

    for (int i=1; i < s; i += 2) {
        if (S.at(i) == '+') {
            n++;
        }
        else if (S.at(i) == '-') {
            n--;
        }
    }

    cout << n << endl;
}
