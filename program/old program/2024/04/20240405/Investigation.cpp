// Investigation 
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<ll>;
const ll INF = 1e18, mod = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    int s = 1, t = n;
    using AI = array<ll, 2>;
    vector<vector<AI>>  G(n + 1);
    VI D(n + 1, INF), S(n + 1, 0), mx(n + 1, 0), mn(n + 1, INF), vis(n + 1);
    for(int i = 1, x, y, z; i <= m; i++) 
        cin >> x >> y >> z, G[x].push_back({y, z});
    D[s] = mn[s] = 0; S[s] = 1;
    priority_queue<AI, vector<AI>, greater<AI>> q;
    q.push({0, s});
    while(!q.empty()) {
        ll x = q.top()[1], val = q.top()[0];
        q.pop();
        if(D[x] < val) continue;
        for(auto i : G[x]) {
            ll nv = i[1] + D[x], to = i[0];
            if(nv < D[to])  {
                D[to] = nv, S[to] = S[x], mx[to] = mx[x] + 1, mn[to] = mn[x] + 1;
                q.push({nv, to});
            }
            else if(nv == D[to]) {
                (S[to] += S[x]) %= mod, mx[to] = max(mx[x] + 1, mx[to]), mn[to] = min(mn[to], mn[x] + 1);
            }
        }
    }
    cout << D[n] << " " << S[n] % mod<< " " << mn[n] << " " << mx[n] << '\n';
    return 0;
}