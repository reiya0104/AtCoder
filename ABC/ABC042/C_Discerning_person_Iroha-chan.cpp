#include <bits/stdc++.h>
using namespace std;


// ある数値以下の最大の要素
// 配列は重複なしでソート済み
int inf(vector<int> &vec, int &i) {
    int size = vec.size();
    int u = size;
    int l = 0;

    while (u - l > 0) {
        int mid = (u + l) / 2;
        if (mid != size - 1) {
            if (vec.at(mid) <= i && vec.at(mid + 1) > i) {
                return vec.at(mid);
            } else if (vec.at(mid) < i) {
                l = mid + 1;
            } else if (vec.at(mid) > i) {
                u = mid;
            } else {
                return -1;
            }
        } else {
            if (vec.at(mid) > i) {
                u = mid - 1;
            } else {
                return vec.at(mid);
            }
        }
    }
    if (l != size - 1) {
        if (vec.at(l) <= i && vec.at(l + 1) > i) {
            return vec.at(l);
        } else {
            return -1;
        }
    }

    if (vec.at(l) > i) {
        return - 1;
    } else {
        return vec.at(l);
    }

    return -1;
}

int to_int(vector<int> &vec) {
    int ans = 0;
    for (int i = 0; i < vec.size(); i++) {
        ans += (int)(pow(10, i)) * vec.at(i);
    }
    return ans;
}

// 数値を一つ分だけ増加させる
void increment(vector<int> &vec_ans, vector<int> &vec_use, int &i) {
    if (i < vec_ans.size()) {
        auto it = upper_bound(vec_use.begin(), vec_use.end(), vec_ans.at(i));

        // それより大きい値が存在していたら
        if (it != vec_use.end()) {
            // 代入しておわり
            vec_ans.at(i) = *it;
        } else {
            // 存在していなかったら代入して次の桁で繰り上げ
            vec_ans.at(i) = vec_use.at(0);
            i++;
            increment(vec_ans, vec_use, i);
        }
    } else {
        // 0より大きい数値(あることが保証されている)
        int t = *upper_bound(vec_use.begin(), vec_use.end(), 0);

        // 次の位の数を追加
        vec_ans.push_back(t);
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> E;
    for (int i = 0; i < 10; i++) {
        E.push_back(i);
    }

    for (int i = 0; i < K; i++) {
        int D;
        cin >> D;
        E.erase(remove(E.begin(), E.end(), D), E.end());
    }


    int N_size = to_string(N).size();
    vector<int> ans;
    for (int i = 0; i < N_size; i++) {
        int t = ((N % (int)(pow(10, i + 1))) / (int)(pow(10, i)));
        int s = inf(E, t);
        if (s != -1) {
            ans.push_back(s);
        } else {
            exit(1);
        }
    }

    // 数値をもとめる
    while (to_int(ans) < N) {
        int i = 0;
        increment(ans, E, i);
    }

    // 答えを出力
    cout << to_int(ans) << endl;
}
