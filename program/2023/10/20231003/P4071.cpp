/*/
https://vjudge.csgrandeur.cn/contest/584210#problem/G
[SDOI2016] 排列计数
*/
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 1000000 + 5;
const int mod = 1e9 + 7;

int T;
int n, m;
ll fac[maxn], inv[maxn], f[maxn];

ll QuiclPow(ll x, ll y) {
    ll ans = 1;
    while(y != 0) {
        if(y & 1) ans = ans * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ans;
}

void init() {
    fac[0] = 1;
    //inv[0] = 1;
    for(int i = 1; i <= maxn - 5; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = QuiclPow(fac[i], mod - 2);
    }
    f[1] = 0;
    f[2] = 1;
    f[3] = 2;
    for(int i = 4; i <= maxn - 5; i++) {
        f[i] = (i - 1) * (f[i - 1] + f[i - 2]) % mod;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    init();
    while(T--) {
        cin >> n >> m;
        if(n == m) {
            cout << 1 << endl;
            continue;
        }
        if(m == 0) {
            cout << f[n] << endl;
            continue;
        }
        if(n - m == 1) {
            cout << 0 << endl;
            continue;
        }
        cout << fac[n] * inv[m] % mod * inv[n - m] % mod * f[n-m] % mod<< endl;
    }
    return 0;
}