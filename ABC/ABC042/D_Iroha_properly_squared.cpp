#include <bits/stdc++.h>
using namespace std;

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int mass(int a, int b, int &H, int &W, int &A, int &B) {
    // cout << "mass(" << a << ", " << b << ")" << endl;
    if (a > 0 && b > 0 && (a <= H - A || b > B)) {
        if (a == 1 || b == 1) {
            return 1;
        }

        if (b - 1 != B || a <= H - A) {
            return ((mass(a - 1, b, H, W, A, B) % MOD + mass(a, b - 1, H, W, A, B) % MOD) %
                    MOD);
        }

        return mass(a - 1, b, H, W, A, B);
    }
    throw;
    return -1;
}

int main() {
    int H, W, A, B;
    cin >> H >> W >> A >> B;
    cout << mass(H, W, H, W, A, B) << endl;
}
