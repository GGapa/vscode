#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 1e5 + 5;

int n, m; 
vector<int> G[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;

    vector<int> deg(n + 1);
    for(int i = 1, u, v; i <= m; i++) 
        cin >> u >> v, G[v].emplace_back(u), deg[u]++;
    
    priority_queue<int> q;
    rep(i, 1, n) if(deg[i] == 0) q.emplace(i);

    vector<int> ans(n + 1); ans[0] = n;
    while(!q.empty()) {
        int x = q.top(); q.pop();
        ans[x] = ans[0]--;
        for(auto to : G[x]) {
            if(--deg[to] == 0) q.emplace(to);
        }
    }

    rep(i, 1, n) cout << ans[i] << " \n"[i == n];
    return 0;
}