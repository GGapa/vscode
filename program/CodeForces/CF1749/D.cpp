#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int mod = 998244353;

LL qpow(LL x, LL y){
    LL ret=  1;
    for(; y; y >>= 1) {
        if(y & 1) (ret = ret * x) %= mod;
        (x = x * x) %= mod;
    }
    return ret;
}

LL inv(int x) {return qpow(x, mod - 2); }
 
LL add(const __int128 x, const __int128 y) {
    return (x + y + mod) % mod;
} 
 
LL mul(const __int128 x, const __int128 y) {
    return (x * y % mod + mod) % mod;
}

const int N = 3e5 + 5;

int vis[N];
vector<int> p;
 
void init() {
    p.emplace_back(-1);
    for (int i = 2; i <= N - 5; i++) {
        if (!vis[i]) p.push_back(i);
        for (int j = 1; j <= p.size() && i * p[j] <= N - 5; j++) {
            vis[i * p[j]] = 1;
            if (i % p[j] == 0) break;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    LL n, m; cin >> n >> m;
    if(n == 1) return cout << m % mod << '\n', 0;
    init();
    vector<__int128> F(n + 1);
    LL up = qpow(m, n), num = 1, ans = 0;
    F[1] = m % mod;
    rep(i, 1, n) {
        num = mul(num, m);
        if(i > 1) ans = add(ans, num);
    }
    num = 1; 
    rep(i, 2, n) {
        if(!vis[i]) num = num * i;
        if(num > m)  break;
        F[i] = mul(F[i - 1], m / num % mod);
        // cout << F[i] << endl;
        ans = add(ans, -F[i] % mod);
    }
    cout << ans << '\n';
    return 0;
}
/*
985402003
32050323
249905439
336764546
973764240
429488488
891979287
633713193
806090175
72340820
760422459
105271415
853175857
552991290
107738227
215476454
430952908
861905816
725567279
452890205
669298485
*/