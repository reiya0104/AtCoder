#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, L;
    vector<string> S;
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        S.push_back(s);
    }
    sort(S.begin(), S.end());
    for (string s : S) {
        cout << s;
    }
    cout << endl;
}
