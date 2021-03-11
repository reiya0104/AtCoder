#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001000;

int main() {
    string s;
    cin >> s;

    map<char, int> data;
    for (int i = 0; i < s.size(); ++i) {
        if (data.count(s.at(i))) data.at(s.at(i)) += 1;
        else data[s.at(i)] = 1;
    }

    string res = "Yes";
    for (int i = 0; i < s.size(); ++i) {
        if (data.at(s.at(i)) & 1 == 1) {
            res = "No";
            break;
        }
    }

    cout << res << endl;
}
