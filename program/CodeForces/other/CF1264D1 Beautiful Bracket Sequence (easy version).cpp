#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

const int mod = 998244353, N = 1e6 + 5;

LL qpow(LL x, LL y){
    LL ret=  1;
    for(; y; y >>= 1) {
        if(y & 1) (ret = ret * x) %= mod;
        (x = x * x) %= mod;
    }
    return ret;
}
 
LL inv(int x) {return qpow(x, mod - 2); }

LL fac[N], iv[N];

LL add(const LL x, const LL y) {
	return (x + y + mod) % mod;
} 

LL mul(const LL x, const LL y) {
	return (x * y % mod + mod) % mod;
}

void init() {
	fac[0] = 1;
	rep(i, 1, N - 1) fac[i] = mul(fac[i - 1], i);
	iv[N - 1] = inv(fac[N - 1]); 
	per(i, N - 2, 0) iv[i] = mul(iv[i + 1], i + 1) ;
    iv[0] = 1;
}

LL C(int x, int y) {
    if(x < 0 || y < 0 || y - x < 0) return 0;
	return mul(fac[y], mul(iv[x], iv[y - x])) ;
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    string s; cin >> s;
    int n = s.size(); s = " " + s;
    vector<int> pre(n + 1), suf(n + 2), S(n + 1);
    rep(i, 1, n) pre[i] = pre[i - 1] + (s[i] == '('), S[i] = S[i - 1] + (s[i] == '?');
    per(i, n, 0) suf[i] = suf[i + 1] + (s[i] == ')');   
    LL ans = 0 ;
    rep(i, 1, n - 1) {
        int l = pre[i], r = suf[i + 1], x = S[i], y = S[n] - S[i]; 
        ans = add(ans, add(mul(l, C(y + r - l, x + y)), mul(x, C(y - l + r - 1, x + y - 1))));
    }
    cout << ans << '\n';
    return 0;
}