#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void fail() {cout << -1 << '\n'; exit(0); }

constexpr int N = 2e5 + 5, INF = 1e9;

int deg[N];

#define ls (x << 1)
#define rs (x << 1 | 1)
struct SGT {
    struct Node {
        int mx, mxpos, tag;
        friend Node operator+(const Node &x, const Node &y) {
            Node ret;
            ret.mxpos = (x.mx >= y.mx ? x.mxpos : y.mxpos);
            ret.mx = max(x.mx, y.mx);
            ret.tag = 0;
            return ret;
        };
    }tr[800020];
    int n;
    
    void apply(int x, int v) {tr[x].mx += v, tr[x].tag += v;}
    void pushdown(int x) {
        if(tr[x].tag == 0) return ;
        apply(ls, tr[x].tag); apply(rs, tr[x].tag);
        tr[x].tag = 0;
    }
    void build(int x = 1, int l = 1, int r = -1) {
        if(r == -1) r = n;
        tr[x].mx = -INF; tr[x].tag = 0;
        if(l == r) return tr[x].mxpos = l, void();
        int mid = (l + r) >> 1;
        build(ls, l, mid); build(rs, mid + 1, r);
        tr[x] = tr[ls] + tr[rs];
    }
    void init(int nn) {n = nn; build(); }
    void modify(int L, int R, int v, int x= 1, int l = 1, int r=  -1) {
        if(r == -1) r = n;
        if(L <= l && r <= R) {
            apply(x, v);
            return ;
        }
        int mid = (l + r) >> 1;
        pushdown(x);
        if(L <= mid) modify(L, R, v, ls, l, mid);
        if(mid < R) modify(L, R, v, rs, mid + 1, r);
        tr[x] = tr[ls] + tr[rs];
    }
    int query(int L, int R, int x = 1, int l = 1, int r = -1) {
        if(r == -1) r = n;
        if(tr[x].mx < 0 || R < l || L > r) return -1;
        if(L <= l && r <= R) return tr[x].mxpos;
        pushdown(x);
        int mid = (l + r) >> 1;
        int ret = query(L, R, ls, l, mid); 
        if(ret == -1) ret = query(L, R, rs, mid + 1, r);
        return ret;
    }
    Node qmx(int L, int R, int x = 1, int l = 1, int r = -1) {
        if(r == -1) r = n;
        if(L <= l && r <= R) return tr[x];
        int mid = l +r  >> 1;
        pushdown(x);
        if(L <= mid && mid < R) return qmx(L, R, ls, l, mid) + qmx(L, R, rs, mid + 1, r);
        if(L <= mid) return qmx(L, R, ls, l, mid);
        if(mid < R) return qmx(L, R, rs, mid + 1, r);
        assert(0);
        return Node{};
    }
}tr1, tr2;
#undef ls
#undef rs

signed main() {
    freopen("data.in", "r", stdin);
    freopen("user.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<set<array<int, 2>>> itl(n + 1);
    vector<int> deg(n + 1), ans;
    for(int i = 1, l, r; i <= n; i++)   
        cin >> l >> r, deg[r]++, itl[l].insert({r, i}); 
    rep(i, 1, n) deg[i] += deg[i - 1];
    tr1.init(n); 
    tr2.init(n);
    rep(i, 1, n) tr1.modify(i, i, (deg[i] - i) - (-INF));

    vector<priority_queue<int>> lft(n + 1);
    rep(i, 1, n) lft[i].emplace(-1e9);
    rep(i, 1, n) {
        for(auto a : itl[i]) {
            int od = tr2.qmx(a[0], a[0]).mx;
            lft[a[0]].emplace(-a[1]);
            int nw = lft[a[0]].top();
            tr2.modify(a[0], a[0], nw - od);
        }
        if(tr1.tr[1].mx > 0) fail();
        int r = tr1.query(i, n);
        auto mn = tr2.qmx(1, r);
        mn.mx *= -1;
        if(mn.mxpos < i || mn.mx >= INF || mn.mx <= -INF) fail();

        int od = tr2.qmx(mn.mxpos, mn.mxpos).mx;
        lft[mn.mxpos].pop();
        int nw = lft[mn.mxpos].top();
        tr2.modify(mn.mxpos, mn.mxpos, nw - od);

        ans.emplace_back(mn.mx);

        if(i < mn.mxpos) tr1.modify(i, mn.mxpos - 1, 1);
    }
    int cnt = 0;
    for(auto a : ans) cout << a << " ";
    cout << '\n';
    return 0;
}
/*
g++ yoshino.cpp -o user -O2 -std=c++14 -Wall -Wextra

*/