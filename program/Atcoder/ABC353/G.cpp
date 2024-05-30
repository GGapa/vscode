#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long 
using VI = vector<int>;


#define ls (x << 1)
#define rs ((x << 1) + 1)

struct SegTree {
    int n; 
    struct Node {
        ll mx, tag;
    };
    vector<Node> T;
    SegTree(int _n) : n(_n), T((n << 2) + 1) {}
    void apply(int x, int v) {
        T[x].mx = v;
        T[x].tag = v;
    }
    void pushdown(int x) {
        if(!T[x].tag) return ;
        apply(ls, T[x].tag);
        apply(rs, T[x].tag);
        T[x].tag = 0;
    }
    void update(int L, int R, ll v, int x = 1, int l = 1, int r = -1) {
        if(r == -1) r = n;
        if(L <= l && r <= R) {
            T[x].mx = v;
            T[x].tag = v;
            return ;
        }
        int mid = l + r >> 1;
        pushdown(x);
        if(L <= mid) update(L, R, v, ls, l, mid);
        if(R > mid) update(L, R, v, rs, mid + 1, r);
        T[x].mx = max(T[ls].mx, T[rs].mx);
    }
    ll query(int L, int R, int x = 1, int l = 1, int r = -1) {
        if(r == -1) r = n;
        if(L <= l && r <= R) 
            return T[x].mx;
        ll res = -1e18;
        int mid = l + r >> 1;   
        pushdown(x);
        if(L <= mid) res = max(res, query(L, R, ls, l, mid));
        if(R > mid) res = max(res, query(L, R, rs, mid + 1, r));
        return res;
    }
};

#undef ls
#undef rs

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, c; cin >> n >> c;
    int m; cin >> m;
    vector<ll> F(n+ 1, -1e16);
    SegTree T1(n), T2(n);
    T1.update(2, n, -1e16), T2.update(2, n, -1e16);
    T1.update(1, 1, c), T2.update(1, 1, -c);
    F[1] = 0;
    rep(i, 1, m) {
        int t, p; cin >> t >> p;
        int l1 = T1.query(1, t);
        int l2 = T2.query(t, n);
        F[t] = max(F[t], max(l1 - c * t, l2 + c * t) + p);
        T1.update(t, t, F[t] + t * c), T2.update(t, t, F[t] + t * -c);
    }
    cout << *max_element(F.begin(), F.end());
    return 0;
}