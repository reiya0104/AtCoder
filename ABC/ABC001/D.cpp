#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> data(N), data2;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        istringstream a, b;
        int A, B;
        a = istringstream(s.substr(0, 4));
        a >> A;
        b = istringstream(s.substr(5));
        b >> B;
        A = (A / 5) * 5;
        B = (B / 5) * 5 + 5 * (B % 5 != 0);
        data.at(i) = make_pair(A, B);
    }
    sort(data.begin(), data.end());
    // for (auto v : data) {
    //     cout << v.first << " " << v.second << endl;
    // }
    int j = 0;
    data2.push_back(data.at(0));
    for (int i = 1; i < N; i++) {
        if ((data.at(i - 1).second >= data.at(i).first) &&
            (data.at(i - 1).second < data.at(i).second)) {
            data2.at(j).second = data.at(i).second;
        } else {
            if ((data2.at(j).second <= data.at(i).first) && (data2.at(j) != data.at(i))) {
                j += 1;
                data2.push_back(data.at(i));
            }
        }
    }
    // for (auto v : data2) {
    //     cout << v.first << " " << v.second << endl;
    // }

    // set<pair<int, int>> data_set(data2.begin(), data2.end());
    // vector<pair<int, int>> data3(data_set.begin(), data_set.end());
    // cout << endl;
    // for (auto v : data2) {
    //     cout << v.first << " " << v.second << endl;
    // }
    for (int i = 0; i < min(N, 2); i++) {
        printf("%04d-%04d\n", data2.at(i).first, data2.at(i).second);
    }
}
