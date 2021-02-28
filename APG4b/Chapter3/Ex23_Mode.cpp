#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    map<int, int> data;
    priority_queue<int> mode;
    int mode_key = 0;
    cin >> N;
    for (int i=0; i < N; i++) {
        int A;
        cin >> A;
        data[A]++;
        mode.push(data[A]);
        if (mode.top() == data[A]) {
            mode_key = A;
        }
    }
    cout << mode_key << " " << mode.top() << endl;

}
