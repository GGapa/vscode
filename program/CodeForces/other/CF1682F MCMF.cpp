#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define int long long
using namespace std;
using LL = long long;
using VI = vector<int>;
const int mod = 1e9 + 7;

struct BIT {
    int n;
    vector<LL> T;
    LL addd(const LL x, const LL y) {
        return (x + y + mod) % mod;
    } 
    LL mul(const LL x, const LL y) {
        return (x * y % mod + mod) % mod;
    }
    BIT(int _n) : n(_n + 1) ,T(_n + 5) {    };
    int lowbit(int x) {return x & -x;}
    void add(int x, LL v) {
        for(++x; x <= n; x += lowbit(x)) T[x] = addd(T[x], v);
    }
    LL ask(int x) {
        LL res = 0;                                 // 不赋初值见祖宗！！！！！ 
        for(++x; x > 0; x -= lowbit(x)) res = addd(res, T[x]);
        return res;
    }
    LL query(int l, int r) {
        if(l > r) return 0;
        return addd(ask(r), -ask(l)); 
    }
    void clear() {fill(T.begin(), T.end(), 0); }
};

LL add(const LL x, const LL y) {
    return (x + y + mod) % mod;
} 
LL mul(const LL x, const LL y) {
    return (x * y % mod + mod) % mod;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<LL> A(n + 1), B(n + 1) ;
    rep(i, 0, n - 1) cin >> A[i];
    per(i, n - 1, 1) A[i] = add(A[i], -A[i - 1]);
    rep(i, 1, n) cin >> B[i], B[i] = B[i - 1] + B[i];
    vector<array<LL, 4>> qr(m + 1);
    rep(i, 1, m) {
        int l, r; cin >> l >> r; l--;
        qr[i] = {B[l], l, r, i};
    }
    sort(qr.begin() + 1, qr.end());
    
    vector<int> id(n) ;
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](const int &x, const int &y) {
        return B[x] < B[y];
    });

    BIT sp(n + 1), cp(n + 1), sn(n + 1), cn(n + 1);
    rep(i, 0, n - 1) {
        sp.add(i, mul(B[i] % mod, A[i]));
        cp.add(i, A[i]);
    }
    vector<int> ans(m + 1);
    int j = 0;
    rep(tt, 1, m) {
        int v = qr[tt][0], l = qr[tt][1], r = qr[tt][2], i = qr[tt][3];
        while (j < n && B[id[j]] <= v) {
            int k = id[j++];
            sp.add(k, -mul(B[k] % mod, A[k]));
            cp.add(k, -A[k]);
            sn.add(k, mul(B[k] % mod, A[k]));
            cn.add(k, A[k]);
        }
        ans[i] = add(add(sp.query(l, r), -sn.query(l, r)), mul(add(cn.query(l, r), -cp.query(l, r)), v));
    }
    rep(i, 1, m) cout << (ans[i] % mod + mod) % mod << '\n';
    return 0; 
}
/*
0
4
2
5
7
1
3
6
*/