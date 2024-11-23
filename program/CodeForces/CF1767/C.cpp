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
 
LL add(const LL x, const LL y) {
    return (x + y + mod) % mod;
} 
 
LL mul(const LL x, const LL y) {
    return (x * y % mod + mod) % mod;
}
 

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> fa(n + 1) ;
    iota(fa.begin(), fa.end(), 0);
    auto find = [&](int x) {
        while(x != fa[x]) fa[x] = x = fa[fa[x]];
        return x;
    };
    vector<VI> A(n + 1, VI(n + 1));
    rep(i, 1, n) rep(j, i, n) cin >> A[i][j];
    rep(i, 1, n) rep(j, i, n) if(A[i][j] == 1) {
        rep(k, i, j) {
            int x = find(i), y = find(k);
            if(x == y) continue;
            fa[y] = x;
        }
    }
    vector<int> vis(n + 1), id(n + 1), S(n + 1);
    vector<int> mx(n + 1);
    rep(i, 1, n) rep(j, i, n) if(A[i][j] == 2) {
        if(find(i) == find(j)) return cout << 0 << '\n', 0;
        mx[j] = max(mx[j], i + 1);
    }
    vector<VI> F(n + 1, VI(n + 1));
    F[1][1] = 1;
    rep(i ,2, n) {
        for(int j = mx[i]; j <= find(i); j++) F[i][j] = F[i - 1][j];
        if(find(i) == i) {
            rep(j, 1, n - 1) (F[i][i] += F[i - 1][j]) %= mod;
        }
    }
    LL ans = 0;
    for(int i = find(i); i <= n; i++) (ans += F[n][i]) %= mod;
    cout << ans * 2 % mod<< '\n';
    return 0;
}