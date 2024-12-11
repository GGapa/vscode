// 这回只花了 30 min 就打完了
// 一点都不好，这么傻逼的题做这么久。
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> A(n + 1), lst(m + 1);
    rep(i, 1, n) cin >> A[i], lst[A[i]] = i;
    vector<int> s, vis(m + 1);
    rep(i, 1, n) if(!vis[A[i]]){ 
        while(!s.empty() && A[s.back()] > A[i] && lst[A[s.back()]] > i) vis[A[s.back()]] = 0, s.pop_back();
        s.emplace_back(i); vis[A[i]] = 1;
    }
    for(auto a : s) cout << A[a] << " ";
    cout << '\n';
}

signed main() {
    freopen("magic.in", "r", stdin);
    freopen("magic.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}