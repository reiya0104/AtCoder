#include <bits/stdc++.h>
using namespace std;

int int_eq(vector<string> vec, map<string, int> data_int) {
    int ans = 0;
    int i_0;
    if (vec.at(0) == "int") {
        i_0 = 3;
    } else if (vec.at(0) == "print_int") {
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

vector<int> vec_eq(vector<string> vec, map<string, int> data_int,
                   map<string, vector<int>> data_vec) {
    vector<int> ans;
    int i_0;
    if (vec.at(0) == "vec") {
        i_0 = 3;
    } else if (vec.at(0) == "print_vec") {
        i_0 = 1;
    }
    int i = i_0;
    int vec_len = 0;
    if (i == i_0) {
        if (vec.at(i) == "[") {
            i++;
            while (vec.at(i) != "]") {
                if (data_int.count(vec.at(i))) {
                    ans.push_back(data_int.at(vec.at(i)));
                    vec_len += 1;
                }
                i++;
            }
        } else if (data_vec.count(vec.at(i))) {
            vec_len = data_vec.at(vec.at(i)).size();
            ans = data_vec.at(vec.at(i));
        }
        i++;
    }
    int op;
    while (i < vec.size()) {
        if (vec.at(i) == "+") {
            op = 1;
        } else if (vec.at(i) == "-") {
            op = -1;
        } else if (vec.at(i) == "[") {
            i++;
            for (int j = 0; j < vec_len; j++) {
                ans.at(j) += op * data_int.at(vec.at(i));
                i += 2;
            }
            i--;
        } else if (data_vec.count(vec.at(i))) {
            for (int j = 0; j < vec_len; j++) {
                ans.at(j) += op * data_vec.at(vec.at(i)).at(j);
            }
        }
        i++;
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

void vec_exp(vector<string> vec, map<string, int> data_int,
             map<string, vector<int>> &data_vec) {
    string var = vec.at(1);
    data_vec[var] = vec_eq(vec, data_int, data_vec);
}

// 問題文の形式でvec値を出力
void print_vec(vector<string> vec, map<string, int> data_int,
               map<string, vector<int>> &data_vec) {
    vector<int> ans = vec_eq(vec, data_int, data_vec);
    cout << "[ ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans.at(i) << " ";
    }
    cout << "]" << endl;
}

int main() {
    int N;
    cin >> N;
    map<string, int> data_int;
    map<string, vector<int>> data_vec;
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

    for (int i = 0; i < N; i++) {
        if (data.at(i).at(0) == "int") {
            int_exp(data.at(i), data_int);
        }
        if (data.at(i).at(0) == "print_int") {
            print_int(data.at(i), data_int);
        }
        if (data.at(i).at(0) == "vec") {
            vec_exp(data.at(i), data_int, data_vec);
        }
        if (data.at(i).at(0) == "print_vec") {
            print_vec(data.at(i), data_int, data_vec);
        }
    }
}
