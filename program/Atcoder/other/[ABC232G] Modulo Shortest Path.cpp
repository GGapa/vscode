#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 2e5 + 5;
const LL INF = 1e18;

int A[N], B[N], id[N], exc[N];
int mod;

#define ls (x << 1) 
#define rs ((x << 1) | 1)
namespace SGT {   
    static const int N = (int)2e5 << 2;
    struct Node {
        int minapos, minvpos;
        LL tag, minval, mina;
    }tr[N];
    int n;
    void pushup(int x) {
        tr[x].minval = min(tr[ls].minval, tr[rs].minval);
        tr[x].mina = min(tr[ls].mina, tr[rs].mina);
        tr[x].minvpos = tr[ls].minval <= tr[rs].minval ? tr[ls].minvpos : tr[rs].minvpos;
        tr[x].minapos = tr[ls].mina <= tr[rs].mina ? tr[ls].minapos : tr[rs].minapos;
    }
    void build(int x = 1, int l = 1, int r = n) {
        tr[x].tag = INF;
        if(l == r) return tr[x].mina = A[id[l]], tr[x].minapos = l, tr[x].minval = (id[l] == n ? 0 : INF), tr[x].minvpos = l,  void();
        int mid = l + r >> 1;
        build(ls, l, mid); build(rs, mid + 1, r);
        pushup(x);
    }   
    void init(int nn) {
        n = nn; 
        build();
    }
    void apply(int x, LL v) {
        tr[x].tag = min(tr[x].tag, v);
        if(v + tr[x].mina < tr[x].minval) tr[x].minval = tr[x].mina + v, tr[x].minvpos = tr[x].minapos;
    }
    void pushdown(int x) {
        if(tr[x].tag == INF) return;
        apply(ls, tr[x].tag); apply(rs, tr[x].tag);
        tr[x].tag = INF;
    }
    void modify(int L, int R, LL v, int l = 1, int r = n, int x = 1) {
        if(L <= l && r <= R) return apply(x, v);
        int mid = l + r >> 1;
        pushdown(x);
        if(L <= mid) modify(L, R, v, l, mid, ls);
        if(mid < R) modify(L, R, v, mid + 1, r, rs);
        pushup(x);
    }
    void del(int it, int x = 1, int l = 1, int r = n) {
        if(l == r) return tr[x].minval = tr[x].mina = INF,  void();
        int mid = l + r >> 1;
        pushdown(x);
        if(it <= mid) del(it, ls, l, mid);
        else del(it, rs, mid + 1, r); 
        pushup(x);
    }
}
#undef ls
#undef rs
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n >> mod;
    rep(i, 1, n) cin >> A[i] ;
    rep(i, 1, n) cin >> B[i];
    iota(id, id + 1 + n, 0);
    sort(id + 1, id + 1 + n, [](const int x, const int y) {
        return A[x] < A[y];
    });
    rep(i, 1, n) exc[i] = id[i];
    auto find = [&](LL v) {
        int l = 1, r = n, ret = 1;
        while(l <= r) {
            int mid = l + r >> 1, i = id[mid];
            if(A[i] + v >= mod) r = mid - 1, ret = mid;
            else l = mid + 1;
        }
        return ret;
    };
    SGT::init(n);
    vector<LL> F(n + 1);
    for(int o = 1; o <= n; o++) {
        int it = SGT::tr[1].minvpos, i = id[it];
        F[it] = SGT::tr[1].minval;
        // cout << SGT::tr[1].minvpos << " " << SGT::tr[1].minval << '\n';
        SGT::del(it);
        SGT::modify(1, n, B[i] + F[it]);
        // cout << find(B[i]) << '\n';
        if(B[i] + A[id[n]] >= mod) SGT::modify(find(B[i]), n, B[i] + F[it] - mod);
    }
    rep(i, 1, n) if(id[i] == 1) return cout << F[i] << '\n', 0;
    return 0;
}