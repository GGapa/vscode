#include <bits/stdc++.h>
#include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--
#define int long long
using namespace std;
using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<LL> A(n + 1), B(n + 1);
    rep(i, 1, n) cin >> A[i];
    rep(i, 1, n) B[i] = A[i] + 2 * (i - 1), A[i] += i - 1;
    queue<LL> q;
    map<LL, bool> vis;
    map<LL, vector<LL>> G;
    rep(i, 1, n) if(B[i] > A[i]) G[A[i]].emplace_back(B[i]);
    q.push(n);
    LL ans = n;
    while(!q.empty()) {
        LL x = q.front(); q.pop();
        ans = max(ans, x); vis[x] = 1;
        for(auto to : G[x]) if(!vis[to]) q.push(to), vis[to] = 1;
    }   
    cout << ans  << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}