#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {3, 1, 5, 6, 7, 2, 4};

    auto itr1 = a.begin();  // aの先頭を指すイテレータ
    itr1 = itr1 + 2;        // a[2]を指すイテレータ
    auto itr2 = itr1 + 4;   // 末尾の要素(a[6])を指すイテレータ

    cout << *itr1 << endl;  // itr1が指す要素(a[2])へのアクセス
    cout << *itr2 << endl;  // itr2が指す要素(a[6])へのアクセス
}
