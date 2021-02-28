#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    vector<tuple<string, int, int>> data;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string S;
        int P;
        cin >> S >> P;
        data.push_back(make_tuple(S, P, i + 1));
    }
    sort(data.begin(), data.end());

    vector<vector<tuple<int, string, int>>> data2;
    int j = 0;
    for (int i=0; i < N; i++) {
        string S;
        int P, k;
        tie(S, P, k) = data.at(i);
        if (i == 0) {
            data2.push_back({make_tuple(P, S, k)});
        }
        else {
            if (get<0>(data.at(i)) == get<0>(data.at(i-1))) {
                data2.at(j).push_back(make_tuple(P, S, k));
            }
            else {
                data2.push_back({make_tuple(P, S, k)});
                j++;
            }
        }
    }

    for (auto u : data2)
    {
        sort(u.begin(), u.end());
        reverse(u.begin(), u.end());
        for (auto v : u) {
            cout << get<2>(v) << endl;
        }
    }
}
