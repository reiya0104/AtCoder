#include <bits/stdc++.h>
using namespace std;

bool check_s(string &s, int i) {
    int size = s.size();
    if (size - i < 5) return false;

    if (s.at(i) == 'd' && s.at(i + 1) == 'r' && s.at(i + 2) == 'e' &&
        s.at(i + 3) == 'a' && s.at(i + 4) == 'm') {
        if (i + 5 == size)
            return true;
        else if (i + 6 == size)
            return false;
        else if (s.at(i + 5) == 'e' && s.at(i + 6) == 'r') {
            if (i + 7 == size)
                return true;
            else if (s.at(i + 7) == 'a')
                return check_s(s, i + 5);
            return check_s(s, i + 7);
        }
        return check_s(s, i + 5);
    } else if (s.at(i) == 'e' && s.at(i + 1) == 'r' && s.at(i + 2) == 'a' &&
               s.at(i + 3) == 's' && s.at(i + 4) == 'e') {
        if (i + 5 == size)
            return true;
        else if (s.at(i + 5) == 'r') {
            if (i + 6 == size) return true;
            return check_s(s, i + 6);
        }
        return check_s(s, i + 5);
    }
    return false;
}

int main() {
    string S;
    cin >> S;
    if (check_s(S, 0))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
