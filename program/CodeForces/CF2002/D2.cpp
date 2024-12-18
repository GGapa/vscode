#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 1e6 + 5;

set<int> G[N];
int n, q, m;
int A[N], F[N], lc[N], rc[N], si[N], ff[N];

void dfs(int l, int r, int fa, int dep) {
    int t = A[l];
    si[l] = m - dep - 1;
    if(!dep) return ;
    int len = (r - l) / 2;
    dfs(l + 1, l + len, A[l], dep - 1);
    dfs(l + len + 1, r, A[l], dep - 1);
    lc[l] = l + 1, rc[l] = l + len + 1;
    ff[lc[l]] = l, ff[rc[l]] = l;
    return ;
}

#define ls (x << 1)
#define rs ((x << 1) | 1)

bool isson(int x, int y) {
    return y == ls || y == rs;
}

void update(int x) {
    if(x == 0) return ;
    int t = __lg(A[x]);
    if(t != si[x]) F[x] = false;
    else if(t == m - 1) F[x] = 1;
    else F[x] = isson(A[x], A[lc[x]]) && F[lc[x]] && isson(A[x], A[rc[x]]) && F[rc[x]];
    update(ff[x]);
}

#undef ls
#undef rs

void solve() {
    cin >> n >> q;
    vector<int> fa(n + 1);
    fill(F + 1, F + 1 + n, 0);
    rep(i, 2, n) cin >> fa[i];
    rep(i ,1, n) cin >> A[i];
     m = __lg(n) + 1;
    dfs(1, n, 0, m - 1);
    rep(i, 1, n) if(si[i] == m - 1) update(i);
    for(int i = 1, x, y; i <= q; i++) {
        cin >> x >> y;
        swap(A[x], A[y]);
        update(x), update(y);
        cout << (F[1] ? "YES" : "NO") << '\n';
    }
    rep(i, 1, n) G[i].clear();
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
} 