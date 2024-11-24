#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    string s; cin >> s; s = " " + s;
    vector<int> vis(n + 1), bel(n + 2);
    vector<int> l(n + 1), r(n + 1);
    int tot = 0;
    rep(i, 1, n) {
        bel[i] += bel[i - 1];
        if(vis[i]) continue;
        int mn = n, mx = 1;
        for(int j = i; !vis[j]; j = A[j])  {
            vis[j] = 1;
            mn = min(j, mn); mx = max(mx, j);
        }
        if(bel[i] == 0){
            bel[mn] += ++tot; bel[mx + 1] -= tot;
            l[tot] = mn, r[tot] = mx;
        }
        else {
            bel[r[tot] + 1] += tot;
            r[tot] = max(r[tot], mx);
            bel[r[tot] + 1] -= tot;
        }
    }
    // rep(i, 1, n) cerr << bel[i] << " \n"[i == n];

    vector<int> cnt(n + 1);
    int ok = 0;

    auto check = [&](int i) {
        if(i == r[bel[i]]) return 0;
        return (int)(s[i] == 'L' && s[i + 1] == 'R');
    } ;

    rep(i, 1, n ) cnt[bel[i]] += check(i);
    rep(i, 1, tot) ok += (cnt[i] == 0);

    for(int x; q--; ) {
        cin >> x;
        int i = bel[x];
        if(cnt[i] == 0) ok--;
        cnt[i] -= check(x) + check(x - 1);
        s[x] = (s[x] == 'L' ? 'R' : 'L');
        cnt[i] += check(x) + check(x - 1);
        if(cnt[i] == 0) ok++;
        cout << (ok == tot ? "YES\n" : "NO\n");
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
/*
结论 1 r 到 l 可以自由过度
但是 l 到 r 不行
*/