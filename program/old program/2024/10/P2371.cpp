// cao,,没想到这辈子 Dijkstra 还能够写挂
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 5e5 + 5;
const LL  inf = 1e18;

vector<pair<int, int>> G[N];


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; LL l, r; cin >> n >> l >> r;
    int x = 0;
    rep(i, 1, n) {
        int y;
        if(x == 0) {
            cin >> x; 
            continue;
        }
        cin >> y;
        if(y == 0) continue;
        rep(j, 0, x - 1) G[j].push_back({(j + y) % x, y});
    }

    priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> q;
    vector<LL> d(x + 1, inf);
    q.push({0, 0}); d[0] = 0;
    while(!q.empty()) { 
        int xx = q.top().second, vv = q.top().first;  q.pop();
        if(d[xx] < vv) continue;
        for(auto to : G[xx]) if(d[to.first] > d[xx] + to.second) d[to.first] = d[xx] + to.second, q.push({d[to.first], to.first});
    }
    
    LL ans = 0;
    l--;
    rep(i, 0, x - 1) {
        if(r >= d[i]) ans += (r - d[i]) /  x + 1;
        if(l >= d[i]) ans -= ((l - d[i]) / x + 1);
        // cerr << ans <    < '\n'67;
    }
    cout << ans << '\n';

    return 0;
}