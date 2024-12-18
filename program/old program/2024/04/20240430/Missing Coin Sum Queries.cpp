// Missing Coin Sum Queries. CSES 2184
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;

struct SegTree {
    int n, idx = 0;
    struct Node {
        int ls, rs;
        ll sum;
    };
    vector<Node> T;
    SegTree(int _n) : n(_n), T(2e5 * 32){}
    int modify(int it, int ls, int l = 1, int r = -1) {
        if(r == -1) r = n;  
        int nw = ++idx, mid = l + r >> 1;
        // T.push_back(T[ls]);
        T[nw] = T[ls];
        if(l == r) return T[nw].sum = T[ls].sum + it, nw;
        if(it <= mid) T[nw].ls = modify(it, T[ls].ls, l, mid);
        else T[nw].rs = modify(it,T[ls].rs, mid + 1, r);
        T[nw].sum = T[T[nw].ls].sum + T[T[nw].rs].sum;
        return nw;
    }
    ll query(int L, int R, int v, int l = 1, int r = -1) {
        if(r == -1) r = n;
        // cout << L << " " << R << " " << v << " " << l << " " << r << '\n';
        if(L == R) return 0;
        if(v == r) return T[R].sum - T[L].sum;
        int mid = l + r >> 1;
        if(v <= mid) return query(T[L].ls, T[R].ls, v, l, mid);
        return T[T[R].ls].sum - T[T[L].ls].sum + query(T[L].rs, T[R].rs, v, mid + 1 ,r);
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    SegTree ST(1e9);
    vector<int> T(n + 1);
    for(int i = 1, x; i <= n; i++) cin >> x, T[i] = ST.modify(x, T[i - 1]);
    for(int i = 1, l, r; i <= q; i++) {
        cin >> l >> r;
        ll ans = 0;
        for(ll x; (x = ST.query(T[l - 1], T[r], min((ll)1e9, ans + 1))) > ans; ans = x)
             ; 
        cout << ans + 1 << '\n';
    }
    return 0;
}
