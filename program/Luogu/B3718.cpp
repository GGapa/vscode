/*
B3718 扔骰子问题 1
https://www.luogu.com.cn/problem/B3718
*/
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 5e6 + 5;
const ll mod = 998244353;

int n, m, T;
ll inv[maxn], mul[maxn], ans, mul5[maxn], inv6[maxn];

ll Pow(ll a, ll b) {
    if(b == 0) return 1;
    ll tmp = Pow(a, b / 2);
    tmp = tmp * tmp % mod;
    if(b & 1)tmp = tmp * a % mod;
    return tmp;
}

void prepar() {
    mul[0] = mul5[0] = 1;
    for(int i = 1; i <= maxn - 5; i++) {
        mul[i] = mul[i - 1] * i % mod;
        mul5[i] = mul5[i - 1] * 5 % mod;
    }
    inv[maxn - 5] = Pow(mul[maxn - 5], mod - 2);
    inv6[maxn - 5] = Pow(Pow(6, maxn - 5), mod - 2);
    for(int i = maxn - 6; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % mod;
        inv6[i] = inv6[i + 1] * 6 % mod;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cout << "tou" << endl;
    cin >> T;
    prepar();
    while(T--) {
        cin >> n >> m;
        ans ^= mul5[n - m] * mul[n] % mod * inv6[n] % mod * inv[m] % mod * inv[n - m] % mod;
    }
    cout << ans << endl;
    return 0;
}