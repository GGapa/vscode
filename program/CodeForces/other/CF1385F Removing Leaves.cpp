#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, k; cin >> n >> k;
    vector<set<int>> G(n + 1) ;
    vector<int> cnt(n + 1);
    for(int i = 1, u, v; i < n; i++) 
        cin >> u >> v, G[u].insert(v), G[v].insert(u); 

    queue<int> q;
    rep(i, 1, n) if(G[i].size() == 1) q.push(i);

    int ans = 0;
    while(!q.empty()) {
        int x = q.front(); q.pop() ;
        if(G[x].empty()) continue;
        int to = *G[x].begin() ;
        G[to].erase(x) ;  cnt[to]++;
        if(cnt[to] == k) {
            cnt[to] = 0; ans++;
            if(G[to].size() == 1) q.push(to) ;
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
