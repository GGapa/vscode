#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define int long long
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, m; cin >> n >> m;
    vector<VI> A(n + 1) ;
    vector<array<int, 3>> mx(n + 1);
    for(int i = 1, x; i <= n; i++) {
        cin >> x;
        A[i].resize(x + 5) ;
        auto &a = A[i];
        a[0] = x;
        rep(i, 1, x) cin >> a[i];
        sort(a.begin() + 1, a.begin() + 1 + x);
        unique(a.begin() + 1, a.begin() + 2 + x);
        int cnt = 0;
        for(int j = 1, xx = 0; j <= x + 2; j++, xx++) {
            if(a[j] != xx) cnt++, mx[i][cnt] = xx, j--;
            if(cnt >= 2) break;
        }
    }
    vector<int> ans(n + 4) ;
    vector<int> id(n + 1) ;
    iota(id.begin(), id.end(), 0) ;
    sort(id.begin(), id.end(), [&](const int &x, const int &y) {
        return mx[x][1] < mx[y][1] ;
    });
    for(int i = n + 2, j = n; i >= 0; i--) {
        while(j >= 1 && mx[id[j - 1]][1] >= i) ans[i] = max({ans[i], ans[mx[id[j]][2]], mx[id[j]][2]}), j--;
        ans[i] = max(ans[i], ans[i + 1]) ;
    }
    rep(i, 0, n + 2) ans[i] = max(ans[i], i);
    LL ret = 0;
    rep(i, 0, min(n + 2, m)) ret += ans[i] ;
    if(m > n + 2) ret += (n + 3 + m) * (m - n - 2) / 2;
    cout << ret << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}