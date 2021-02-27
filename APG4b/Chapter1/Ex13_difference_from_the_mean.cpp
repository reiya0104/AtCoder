#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    int sum = 0;
    cin >> N;
    vector<int> score(N);
    for (int i=0; i < N; i++) {
        cin >> score.at(i);
        sum += score.at(i);
    }
    int avg = sum / N;
    for (int i=0; i < N; i++) {
        int diff = score.at(i) - avg;
        if (diff < 0) {
            diff *= -1;
        }
        cout << diff << endl;
    }

}
