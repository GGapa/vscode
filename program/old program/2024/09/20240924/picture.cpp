#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int mod = 1e9 + 7, N = 2e6 + 1;

LL qpow(LL x, LL y){
    LL ret=  1;
    for(; y; y >>= 1) {
        if(y & 1) (ret = ret * x) %= mod;
        (x = x * x) %= mod;
    }
    return ret;
}
 
LL inv(int x) {return qpow(x, mod - 2); }
 
LL add(const LL x, const LL y) {
    return (x + y + mod) % mod;
} 
 
LL mul(const LL x, const LL y) {
    return (x * y % mod + mod) % mod;
}
 
LL fac[N], iv[N];
 
void init() {
    fac[0] = 1;
    rep(i, 1, N - 1) fac[i] = mul(fac[i - 1], i);
    iv[N - 1] = inv(fac[N - 1]); 
    per(i, N - 2, 0) iv[i] = mul(iv[i + 1], i + 1) ;
}
 
LL C(int y, int x) {
    if(x < 0 || y < 0 || y - x < 0) return 0;
    return mul(fac[y], mul(iv[x], iv[y - x])) ;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    int n, m; cin >> n >> m;
    LL ans = 0;
    rep(i, 1, min(n, m)) {    
        ans = add(ans, C((n - i >> 1) + i - 1, i - 1));
        if(i != 1) ans = add(ans, C((n - i - 1 >> 1) + i - 1, i - 1));
    }
    cout << ans << '\n';
    return 0;
}
/*
对于这种本质不同的题目，应当考虑最普遍的情况，然后根据这种情况来寻找解决方案。
比如这道题：1 2 3 2 1 就可以写为：1 2 1 2 3
通项公式就是  1 (2 1) 2 (3 2) 3 (4 3)  ..... m (m - 1)
最后一个可能是会突出来，需要分开考虑
考虑枚举元素的上界 i 那么就有 n - i 个元素可以自由安放，但是是两个元素一组，所以要除以 2 
t 是上界
因为长度不够的也满足答案，那么就是非负整数下的插板法。
*/