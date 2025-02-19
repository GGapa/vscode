#include <bits/stdc++.h>
// #include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
// using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<int, siz>;

constexpr int N = 2e5 + 5, mod = 998244353;

int n;

#define ls (x << 1)
#define rs (x << 1 | 1)
struct SGT {
    struct Node {
        LL mul = 1, add = 0, sum = 0;
    }tr[N << 2];
    
    void apply(int x, LL len, LL mul, LL add) {
        (tr[x].sum *= mul) %= mod; (tr[x].mul *= mul) %= mod; (tr[x].add *= mul) %= mod;
        (tr[x].add += add) %= mod; (tr[x].sum += len * add % mod) %= mod;
    }
    void pushdown(int x, int l, int r) {
        int mid = l + r >> 1;
        apply(ls, mid - l + 1, tr[x].mul, tr[x].add);
        apply(rs, r - mid, tr[x].mul, tr[x].add);
        tr[x].mul = 1; tr[x].add = 0;
    }
    void pushup(int x) {
        tr[x].sum = (tr[ls].sum + tr[rs].sum) % mod;
    }
    void modify(int op, int v, int L, int R, int x = 1, int l = 1, int r = n) {
        // cerr << x << " " << l << " " << r << '\n';
        if(L <= l && r <= R) return apply(x, r - l + 1, op == 2 ? v : 1, op == 1 ? v : 0);
        pushdown(x, l, r);
        int mid = l + r >> 1;
        if(L <= mid) modify(op, v, L, R, ls, l ,mid);
        if(mid < R) modify(op, v, L, R, rs, mid + 1, r);
        pushup(x);
    }
    int query(int L, int R, int x = 1, int l = 1, int r = n) {
        if(L <= l && r <= R) return tr[x].sum;
        int mid = l + r >> 1, ret  =0;
        pushdown(x, l, r);
        if(L <= mid) (ret += query(L, R, ls, l, mid)) %= mod;
        if(mid < R) (ret += query(L, R, rs, mid + 1, r)) %= mod;
        return ret;
    }
}sgt;
#undef ls
#undef rs

signed main() {
    freopen("data.in", "r", stdin);
    freopen("user.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int q; cin >> n >> q;
    for(int op, l, r, x; q--; ) {
        cin >> op >> l >> r;
        if(op != 4) cin >> x;
        if(op == 1) sgt.modify(1, x, l, r);
        else if(op == 2) sgt.modify(2, 0, l, r), sgt.modify(1, x, l, r);
        else if(op == 3) sgt.modify(2, x, l, r);
        else cout << sgt.query(l, r) << '\n';
        // rep(i, 1, n) cout << sgt.query(i, i) << " \n"[i == n];
    }

    return 0;
}
/*
5 5
1 2 5 10
2 3 3 4
2 2 2 6
4 2 5
4 3 4

0 10 10 10 10 
0 10 4 10 10
0 6 4 10 10
*/