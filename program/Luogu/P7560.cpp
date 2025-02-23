#include <bits/stdc++.h>
// #include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
// using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<LL, siz>;

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
        // cerr << "1 : " << x << ' ' << v << '\n';
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
    int kth(T k) {
        int ret = 0; 
        per(i, __lg(n), 0) if((ret + (1 << i))  <= n && tr[ret + (1 << i)] < k) 
            ret += (1 << i), k -= tr[ret];
        // cerr << ask(5) << '\n';
        return ret;
    }
};

#define ls (x << 1)
#define rs (x << 1 | 1)
struct SGT {
    static constexpr int N = 25e4 + 5;
    static int n;
    struct Node {
        LL val, mn;
    }tr[N << 2];
    friend Node operator+(const Node&x, const Node &y) {
        Node ret = x;
        ret.val += y.val;
        ret.mn = min(x.mn, x.val + y.mn);
        return ret;
    }
    
    void init(int nn) {n = nn; }
    void modify(int it, LL v, int x = 1, int l = 1, int r = n) {
        if(l == r) return tr[x] = {v, v}, void();
        int mid = l + r >> 1;
        if(it <= mid) modify(it, v, ls, l ,mid);
        else modify(it, v, rs, mid + 1, r);
        tr[x] = tr[ls] + tr[rs];
    }
    Node query(int it, int x = 1, int l = 1, int r = n) {
        if(l == r) return tr[x];
        int mid = l + r >> 1;
        if(it <= mid) return query(it, ls, l, mid);
        return tr[ls] + query(it, rs, mid + 1, r);
    } 
}sgt;
#undef ls
#undef rs
int SGT::n;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m, q; cin >> n >> m >> q;
    
    vector<vector<AI<2>>> ad(n + 2), de(n + 2), qu(n + 2);
    vector<int> val(q + 1), vis(q + 1);
    for(LL i = 1, op, l, r, c, k; i <= q; i++) {
        cin >> op >> l >> r;
        if(op == 1) cin >> c >> k, ad[l].push_back({i, k}), ad[r + 1].push_back({i, -k}), val[i] = c;
        if(op == 2) cin >> k, de[l].push_back({i, -k}), de[r + 1].push_back({i, 0});
        if(op == 3) qu[l].push_back({i, r}), vis[i] = 1;
    }

    BIT<LL> bit(q); sgt.init(q);
    vector<int> ans(q + 1);
    rep(i, 1, n) {
        for(auto [a, b] : ad[i]) bit.add(a, b), sgt.modify(a, max(b, 0ll));
        for(auto [a, b] : de[i]) sgt.modify(a, b);
        for(auto [a, b] : qu[i]) {
            // auto [] = sgt.query(a); now = min(now, 0ll);
            auto [now, mn] = sgt.query(a); mn = min(mn, 0ll);
            if(now - mn < b) {
                ans[a] = 0;
                continue;
            }
            
            ans[a] = val[bit.kth(bit.ask(a) + b - (now - mn))];
        }
    }
    rep(i, 1, q) if(vis[i])cout << ans[i] << "\n";

    return 0; 
}
/*

*/