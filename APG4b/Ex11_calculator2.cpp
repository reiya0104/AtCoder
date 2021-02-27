#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    int A;
    string op;
    int B;
    cin >> N >> A;

    for (int i = 1; i <= N; ++i)
    {
        cin >> op >> B;
        if (op == "+")
        {
            A += B;
        }
        else if (op == "-")
        {
            A -= B;
        }
        else if (op == "*")
        {
            A *= B;
        }
        else if (op == "/")
        {
            if (B != 0)
            {
                A /= B;
            }
            else
            {
                cout << "error" << endl;
                break;
            }
        }

        cout << i << ":" << A << endl;
    }
}
