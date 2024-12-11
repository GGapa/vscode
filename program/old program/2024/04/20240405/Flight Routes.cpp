//Flight Routes 
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using VI = vector<int>;
typedef long long ll;
using AI = array<ll, 2>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    vector<vector<AI>> G(n + 1);
    vector<vector<ll>> D(n + 1);
    for(int i = 1, x, y, z; i <= m; i++)
        cin >> x >> y >> z, G[x].push_back({z, y});
    priority_queue<AI, vector<AI>, greater<AI>> q;
    q.push({0, 1});
    while(!q.empty()) {
        auto x = q.top(); q.pop();
        // cout << x[0] << '\n';
        if(D[x[1]].size() >= k) continue;
        D[x[1]].push_back(x[0]);
        for(auto to : G[x[1]]) 
            q.push({x[0] + to[0], to[1]});
    }
    for(auto i : D[n]) cout << i << " ";
    
    return 0;
}