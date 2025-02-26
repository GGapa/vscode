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

constexpr int INF = 1e9;

template <typename T>
struct BIT {
    int n;
    vector<T> tr;
    void init(int nn) {
        n = nn + 1;
        tr.assign(n + 5, T{});
    }
    BIT (int nn = 0) {
        init(nn);
    }
    void add(int x, const T &v) {
        for(++x; x <= n; x += x & -x) tr[x] = (tr[x] + v);
    }
    T ask(int x) {
        T ret{};
        for(++x; x >= 1; x -= x & -x) ret = (ret + tr[x]);
        return ret;
    }
    T query(int l, int r) {
        return ask(r) - ask(l);
    }
};

#define ls (x << 1)
#define rs (x << 1 | 1)
namespace SGT {
    static int n;
    static constexpr int N = 5e5 + 5;
    int tr[N << 2];
    int (*op)(int, int);
    int cmin(int x, int y) {return min(x, y); }
    int cmax(int x, int y) {return max(x, y); }

    void init(int nn, int cho) {n = nn; op = (cho ? cmin : cmax); }
    void modfiy(int it, int v, int x = 1, int l = 1, int r = n) {
        if(l == r) return tr[x] = v, void();
        int mid = l + r >> 1;
        if(it <= mid) modfiy(it, v, ls, l, mid);
        else modfiy(it, v, rs, mid + 1, r);
        tr[x] = op(tr[ls], tr[rs]);
    } 
    int query(int L, int R, int x = 1, int l = 1, int r = n) {
        if(L <= l && r <= R ) return tr[x];
        int mid = l + r >> 1;
        if(L <= mid && mid < R) return op(query(L, R, ls, l, mid), query(L, R, rs, mid + 1, r));
        if(L <= mid) return query(L, R, ls, l, mid);
        if(mid < R) return query(L, R, rs, mid + 1, r);
        assert(0);
        return -1;
    }
}
#undef ls
#undef rs

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, q; cin >> n >> q;
    SGT::init(n, 1);
    vector<int> a(n + 2), h(n + 2);
    rep(i, 1, n) cin >> a[i] >> h[i];
    a[0] = a[1], a[n + 1] = a[n];
    vector<int> L(n + 2), R = L;
    L[1] = 0, R[n] = n + 1;

    SGT::modfiy(1, 0);    
    vector<VI> id(n + 2);
    rep(i, 2, n) {
        int pos = upper_bound(a.begin() + 1, a.begin() + 1 + i, a[i] - h[i]) - a.begin();
        for(auto x : id[i]) SGT::modfiy(x, INF);
        L[i] = min(pos, pos == i ? pos : SGT::query(pos, i - 1));
        SGT::modfiy(i, L[i]);
        id[lower_bound(a.begin() + 1 + i, a.begin() + 1 + n, a[i] + h[i]) - a.begin()].emplace_back(i);
    }
    SGT::init(n, 0);
    SGT::modfiy(n, n + 1);
    rep(i, 1, n) vector<int>().swap(id[i]);
    per(i, n - 1, 1) {
        int pos = lower_bound(a.begin() + 1 + i, a.end(), a[i] + h[i]) - a.begin() - 1;
        for(auto x : id[i]) SGT::modfiy(x, 0);
        R[i] = max(pos, pos == i ? pos : SGT::query(i + 1, pos));
        SGT::modfiy(i, R[i]);
        id[upper_bound(a.begin() + 1, a.begin() + i, a[i] - h[i]) - a.begin() - 1].emplace_back(i);
    }

    vector<VI> G(n + 3); vector<int> cnt(n + 2), ans(q + 2);
    rep(i, 1, n) G[L[i]].push_back(R[i]), cnt[R[i]]++;
    rep(i, 1, n) cnt[i] += cnt[i - 1];
    vector<vector<AI<2>>> ql(n + 2), qr = ql;
    for(int i = 1, x, y; i <= q; i++) 
        cin >> x >> y,  ql[x].push_back({y, i}), qr[y].push_back({x, i}), ans[i] = cnt[y];
    BIT<int> tr(n + 2);
    rep(i, 1, n) {
        for(auto [r, id] : ql[i]) ans[id] -= tr.ask(r);
        tr.add(R[i], 1);
    }
    tr.init(n + 2);
    per(i, n, 1) {
        for(auto [l, id] : qr[i]) ans[id] -= tr.ask(n - l + 1);
        tr.add(n - L[i] + 1, 1);
    }
    tr.init(n + 2);
    
    per(i, n, 1) {
        for(auto x : G[i]) tr.add(n - x + 2, 1);
        for(auto [r, id] : ql[i]) ans[id] += tr.ask(n - r + 1);
    }

    rep(i, 1, q) cout << ans[i] <<  "\n"; 

    return 0;
}
