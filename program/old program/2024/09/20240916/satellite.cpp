// 逆天 124OJ 本机 0.6s 在你上面跑居然要跑 T QAQAQAQAQ
// 逆天 124OJ 本机 0.6s 在你上面跑居然要跑 T QAQAQAQAQ
// 逆天 124OJ 本机 0.6s 在你上面跑居然要跑 T QAQAQAQAQ
// 逆天 124OJ 本机 0.6s 在你上面跑居然要跑 T QAQAQAQAQ
// 逆天 124OJ 本机 0.6s 在你上面跑居然要跑 T QAQAQAQAQ
// 逆天 124OJ 本机 0.6s 在你上面跑居然要跑 T QAQAQAQAQ
// 逆天 124OJ 本机 0.6s 在你上面跑居然要跑 T QAQAQAQAQ
// 逆天 124OJ 本机 0.6s 在你上面跑居然要跑 T QAQAQAQAQ
// 逆天 124OJ 本机 0.6s 在你上面跑居然要跑 T QAQAQAQAQ
// 逆天 124OJ 本机 0.6s 在你上面跑居然要跑 T QAQAQAQAQ
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

int mod;

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
    return ((x + y) % mod + mod) % mod;
} 

LL mul(const LL x, const LL y) {
    return (x * y % mod + mod) % mod;
}

vector<int> init(vector<int> &x) {   
    vector<int> ret = x;
    int n = x.size() - 1;
    sort(x.begin() + 1, x.end());
    x.erase(unique(x.begin() + 1, x.end()), x.end());
    rep(i, 1, n) ret[i] = lower_bound(x.begin(), x.end(), ret[i]) - x.begin();
    return ret;
}

signed main() {
    int t = clock();
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q, w, h, a, b; cin >> n >> q >> w >> h >> mod >> a >> b;
    vector<int> H(n + 1), X(n + 1), Y(n + 1);
    rep(i, 1, n) cin >> H[i] >> X[i] >> Y[i];
    vector<int> nx = init(X), ny = init(Y);
    int ww = w, hh = h;
    w = X.size() - 1; h = Y.size() - 1;
    vector<int> px(w + 1), py(h + 1);
    rep(i, 1, w - 1) px[i] = qpow(a, X[i + 1] - X[i]);
    rep(i, 1, h - 1) py[i] = qpow(b, Y[i + 1] - Y[i]);
    vector<VI> pu(w + 2, VI(h + 2)), pd = pu, su = pu, sd = pu;
    rep(i, 1, n) {
        int &x = nx[i], &y = ny[i];
        pu[x][y] += H[i]; pd[x][y] += H[i]; su[x][y] += H[i]; sd[x][y] += H[i];
    }

    rep(i, 1, w) rep(j, 1, h) pu[i][j] += add(mul(pu[i - 1][j], px[i - 1]) + mul(pu[i][j - 1], py[j - 1]), mul(px[i - 1], py[j - 1]) * pu[i - 1][j - 1] % mod * -1);
    per(i, w, 1) rep(j, 1, h) pd[i][j] += add(mul(pd[i + 1][j], px[i]) + mul(pd[i][j - 1], py[j - 1]), mul(px[i], py[j - 1]) * pd[i + 1][j - 1] % mod * -1);
    rep(i, 1, w) per(j, h, 1) su[i][j] += add(mul(su[i - 1][j], px[i - 1]) + mul(su[i][j + 1], py[j]), mul(px[i - 1], py[j]) * su[i - 1][j + 1] % mod * -1);
    per(i, w, 1) per(j, h, 1) sd[i][j] += add(mul(sd[i + 1][j], px[i]) + mul(sd[i][j + 1], py[j]), mul(px[i], py[j]) * sd[i + 1][j + 1] % mod * -1);

    X.emplace_back(ww), Y.emplace_back(hh);
    for(int x, y; q--; ) {
        cin >> x >> y;
        int ix = lower_bound(X.begin(), X.end(), x) - X.begin();
        int iy = lower_bound(Y.begin(), Y.end(), y) - Y.begin();
        int D = qpow(a, X[ix] - x), U = qpow(a, x - X[ix - 1]), R = qpow(b, Y[iy] - y), L = qpow(b, y - Y[iy - 1]);
        cout << (1ll * U * L % mod * pu[ix - 1][iy - 1] % mod + 1ll * L * D % mod * pd[ix][iy - 1] + 1ll * U * R % mod * su[ix - 1][iy] % mod + 1ll * D * R % mod * sd[ix][iy] % mod) % mod << '\n';
    }
    return 0;
}