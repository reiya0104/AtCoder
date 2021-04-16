/**
 *	author:  reiya0104
 *	created: 14.04.2021 00:03:23
 **/

#include <bits/stdc++.h>
using namespace std;

bool solve(int i, string &s) {
    if (s.at(i) == 'd') {
        int remain_size = s.size() - i;
        if (remain_size < 5 || remain_size == 6)
            return false;
        else if (remain_size == 5) {
            if (s.substr(i) == "dream") return true;
            return false;
        } else if (remain_size == 7) {
            if (s.substr(i) == "dreamer") return true;
            return false;
        } else {
            if (s.substr(i, 7) == "dreamer" &&
                (s.at(i + 7) == 'd' || s.at(i + 7) == 'e')) {
                return solve(i + 7, s);
            } else if (s.substr(i, 5) == "dream") {
                return solve(i + 5, s);
            }
            return false;
        }
    } else if (s.at(i) == 'e') {
        int remain_size = s.size() - i;
        if (remain_size < 5)
            return false;
        else if (remain_size == 5) {
            if (s.substr(i) == "erase") return true;
            return false;
        } else if (remain_size == 6) {
            if (s.substr(i) == "eraser") return true;
            return false;
        } else {
            if (s.substr(i, 6) == "eraser" &&
                (s.at(i + 6) == 'd' || s.at(i + 6) == 'e')) {
                return solve(i + 6, s);
            } else if (s.substr(i, 5) == "erase") {
                return solve(i + 5, s);
            }
            return false;
        }
    }
    return false;
}

int main() {
    string s;
    cin >> s;

    bool res = solve(0, s);
    if (res) cout << "YES" << endl;
    else cout << "NO" << endl;
}
