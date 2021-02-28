#include <bits/stdc++.h>
using namespace std;

int int_eq(vector<string> vec, map<string, int> data_int) {
    int ans = 0;
    int i_0;
    if (vec.at(0) == "int") {
        i_0 = 3;
    }
    else if (vec.at(0) == "print_int") {
        i_0 = 1;
    }
    for (int i = i_0; i < vec.size() - 1; i += 2) {
        if (i == i_0) {
            ans = data_int.at(vec.at(i));
        } else {
            int op;
            if (vec.at(i - 1) == "+") {
                op = 1;
            } else if (vec.at(i - 1) == "-") {
                op = -1;
            }
            int num;
            num = data_int.at(vec.at(i));
            ans = ans + op * num;
        }
    }
    return ans;
}

void int_exp(vector<string> vec, map<string, int> &data_int) {
    string var = vec.at(1);
    data_int[var] = int_eq(vec, data_int);
}

// 問題文の形式でint値を出力
void print_int(vector<string> vec, map<string, int> data_int) {
    cout << int_eq(vec, data_int) << endl;
}

// 問題文の形式でvec値を出力
void print_vec(vector<int> vec) {
    cout << "[ ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec.at(i) << " ";
    }
    cout << "]" << endl;
}

int main() {
    int N;
    cin >> N;
    map<string, int> data_int;
    for (int i = 0; i < 10; i++) {
        data_int[to_string(i)] = i;
    }

    vector<vector<string>> data(N);
    for (int i = 0; i < N; i++) {
        while (true) {
            string S;
            cin >> S;
            data.at(i).push_back(S);
            if (S == ";") {
                break;
            }
        }
    }
    // debug
    cout << "data_int = " << endl;
    // Keyの値が小さい順にループ
    for (auto p : data_int) {
        auto key = p.first;
        auto value = p.second;
        // key, valueを使う
        cout << "key = " << key << ", value = " << data_int[key] << endl;
    }
    cout << endl;
    // debug

    for (auto u : data) {
        for (auto v : u) {
            cout << v << endl;
        }
        cout << endl << endl;
    }
    for (int i = 0; i < N; i++) {
        if (data.at(i).at(0) == "int") {
            // int(data.at(i));
            cout << "data.at(" << i << ").at(0) = 'int'" << endl;
            int_exp(data.at(i), data_int);
        }
        if (data.at(i).at(0) == "print_int") {
            // int(data.at(i));
            cout << "data.at(" << i << ").at(0) = 'print_int'" << endl;
            print_int(data.at(i), data_int);
        }
    }

    // debug
    cout << "data_int = " << endl;
    // Keyの値が小さい順にループ
    for (auto p : data_int) {
        auto key = p.first;
        auto value = p.second;
        // key, valueを使う
        cout << "key = " << key << ", value = " << data_int[key] << endl;
    }
    cout << endl;
    // debug
}
