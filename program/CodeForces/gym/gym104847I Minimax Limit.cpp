#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

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

constexpr int N = 1e5 + 5;  
constexpr double eps = 1e-7;

int n, A;
int a[N];

bool check(double lim) {
    vector<int> op(1); vector<double> len(1);

    auto ad = [&](int col, double L) {
        if(op.size() > 1 && col == op.back())  len.back() += L;
        else op.emplace_back(col), len.emplace_back(L);
    };

    rep(i, 1, n) {
        int l = a[i - 1], r = a[i];
        if(max(l, r) <= lim) ad(0, 1);
        else if(min(l, r) >= lim) ad(1, 1); 
        else if(l < lim && r > lim)
            ad(0, (lim - l) / (r - l)), ad(1, (r - lim) / (r - l));
        else 
            ad(1, (lim - l) / (r - l)), ad(0, (r - lim) / (r - l));
    }

    int nn = op.size() - 1;
    DSU dsu(nn + 3);
    priority_queue<pair<double, int>> q;
    vector<int> nxt(nn + 1); vector<double> nd(nn + 1); 

    auto add = [&](int l) {
        int r = nxt[l];
        int cnt = (l != 1) + (r != nn);
        nd[l] = len[l];
        if(cnt == 0) return ;
        else if(cnt == 1) nd[l] *= 2;
        q.emplace(-nd[l], l);
    };
    
    auto mg = [&](int x, int y) {
        x = dsu.find(x), y = dsu.find(y);
        if(x > y) swap(x, y);
        nxt[x] = nxt[y];
        len[x] += len[y];
        dsu.merge(y, x);
    };

    rep(i, 1, nn) nxt[i] = i, add(i);
    while(q.size() && -q.top().first <= A) {
        int x = q.top().second; double le = -q.top().first;
        q.pop();
        if(dsu.find(x) != x || fabs(nd[x]- le) > eps) continue;
        op[x] ^= 1;
        if(nxt[x] != nn) mg(x, nxt[x] + 1);
        if(x != 1) mg(x - 1, x);
        add(dsu.find(x));
    }
    rep(i, 1, nn) if(dsu.fa[i] == i && op[i] == 1) return false;
    return true;
}

void solve() {
    cin >> n >> A;
    rep(i, 0, n) cin >> a[i];

    double l = -1e6, r = 1e6;
    while(r - l > eps) {
        auto mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid;
        // cerr << l << " " << r << '\n';
    }
    cout << fixed << setprecision(20) << r << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1; 
    // cin >> T;
    while(T--) solve();
    return 0;
}