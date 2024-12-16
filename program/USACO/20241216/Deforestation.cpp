#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
using AI = array<int, 3>;

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

struct DSU {
    vector<int> fa;
    DSU() {}
    DSU(int n) {init(n); }
    void init(int n) {
        fa.resize(n + 1); 
        iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        while(x != fa[x]) x = fa[x] = fa[fa[x]];
        return x;
    }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        fa[x] = y;
        return true;    
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i]; 
    sort(A.begin() + 1, A.end());
    auto tmp = A;
    
    vector<AI> itv(m + 1);
    rep(i ,1, m) rep(j, 0, 2) cin >> itv[i][j], tmp.emplace_back(itv[i][j]);
    sort(tmp.begin() + 1, tmp.end());
    tmp.erase(unique(tmp.begin() + 1, tmp.end()), tmp.end());

    auto find = [&](int x) {return lower_bound(tmp.begin() + 1, tmp.end(), x) - tmp.begin(); };
    int k = tmp.size() - 1;
    rep(i, 1, n) A[i] = find(A[i]);
    rep(i, 1, m) rep(j, 0, 1) itv[i][j] = find(itv[i][j]);

    vector<VI> id(k + 1);
    rep(i, 1, m) id[itv[i][1]].emplace_back(i);

    BIT<int> tr(k + 1); DSU dsu(k + 1);
    rep(i, 1, k) if(!id[i].empty()) {
        int j = dsu.find(upper_bound(A.begin() + 1, A.end(), i) - A.begin() - 1);
        for(auto c : id[i]) {
            int l = itv[c][0], r = itv[c][1], w = itv[c][2];
            while(tr.query(l - 1, r) < w) {
                tr.add(A[j], 1);
                dsu.merge(j, j - 1);
                j = dsu.find(j);
            }
        }
    }

    cout << n - tr.ask(k) << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}