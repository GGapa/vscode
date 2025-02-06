#include <bits/stdc++.h>
#include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<int, siz>;

struct DSU {
    vector<int> fa, sz;
    DSU() {}
    DSU(int n) {init(n); }
    void init(int n) {
        fa.resize(n + 1);  sz.assign(n + 1, 1);
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
        sz[y] += sz[x];
        return true;    
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

void solve() {
    int n, __; cin >> n >> __;
    vector<int> A(n + 3); vector<LL> S(n + 3);
    rep(i, 1, n) cin >> A[i], S[i] = S[i - 1] + A[i];
    A[0] = A[n + 1] = INT_MAX;
    DSU dsu(n + 4);

    vector<AI<2>> tr(n + 1);
    vector<int> ans(n + 1), st(n + 1);
    int top = 0;
    rep(i, 1, n) {
        while (top && A[st[top]] < A[i]) -- top;
        tr[i][0] = tr[st[top]][1], tr[st[top]][1] = i;

        if (tr[i][0] && S[i - 1] - S[st[top]] >= A[i]) dsu.merge(tr[i][0], i);
        st[++ top] = i;
        
        int f = dsu.find(st[1]), u = tr[f][1];
        while (u) {
            if (S[i] - S[f] >= A[f]) dsu.merge(f, u);
            f = dsu.find(u), u = tr[f][1];
        }
        ans[i] = dsu.sz[dsu.find(st[1])];
    }
    rep(i, 1, n) cout << ans[i] << " \n"[i == n];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}