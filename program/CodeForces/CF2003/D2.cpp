#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define int long long
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 2e5 + 5;
// vector<int> G[N];

void solve() {
    int n, m; cin >> n >> m;
    int nn = 0;
    vector<VI> A(n + 1) ;
    vector<array<int, 3>> mx(n + 1);
    for(int i = 1, x; i <= n; i++) {
        cin >> x;
        A[i].resize(x + 5) ;
        auto &a = A[i];
        a[0] = x;
        rep(i, 1, x) cin >> a[i];
        nn = max(nn, x);
        sort(a.begin() + 1, a.begin() + 1 + x);
        unique(a.begin() + 1, a.begin() + 2 + x);
        int cnt = 0;
        for(int j = 1, xx = 0; j <= x + 2; j++, xx++) {     // 槽点 1，找 mex 找的太差了。
            if(a[j] != xx) cnt++, mx[i][cnt] = xx, j--;
            if(cnt >= 2) break;
        }
    }
    vector<int> ans(nn + 4) ;
    vector<VI> G(nn + 4) ;
    vector<int> id(n + 1) ;
    iota(id.begin(), id.end(), 0) ;
    sort(id.begin(), id.end(), [&](const int &x, const int &y) {
        if(mx[x][1] != mx[y][1]) return mx[x][1] < mx[y][1] ;
        return mx[x][2] < mx[y][2] ;
    });
    int mxx = 0, mx2 = 0;
    set<int> s;
    rep(c, 1, n) {
        int i = id[c];
        if(s.count(mx[i][1])) s.insert(mx[i][2]) ;
        s.insert(mx[i][1]) ;
        G[mx[i][2]].push_back(mx[i][1]);
    }
    function<void(int, int)> dfs = [&](int x, int v) {
        ans[x] = v;
        for(auto to : G[x]) if(ans[to] < v) dfs(to, v) ; 
    };
    per(i, nn + 2, 0) if(ans[i] < i) dfs(i, i);
    mx2 = *s.rbegin();
    rep(i, 0, nn + 2) ans[i] = max({ans[i], mx2, i});
    LL ret = 0;
    rep(i, 0, min(nn + 2, m)) ret += ans[i] ;
    if(m > nn + 2) ret += (nn + 3 + m) * (m - nn - 2) / 2;
    cout << ret << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
