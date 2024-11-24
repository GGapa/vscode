#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
// #define int unsigned long long
using LL = unsigned long long;
using VI = vector<int>;
const int N = 1e5 + 5;
const LL inf = (1ull << 63) - 1;
vector<pair<int, int>> G[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    LL h; cin >> h; h--;
    int x, y, z; cin >> x >> y >> z;
    rep(i, 0, x - 1) G[i].push_back({(i + y) % x, y}), G[i].push_back({(i + z) % x, z});
    priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> q;
    vector<LL> d(x + 1, inf);
    q.push({0, 0}); d[0] = 0;
    while(!q.empty()) { 
        int xx = q.top().second; 
        if(d[xx] < q.top().first) continue;
        q.pop();
        for(auto to : G[xx]) if(d[to.first] > d[xx] + to.second) d[to.first] = d[xx] + to.second, q.push({d[to.first], to.first});
    }
    // rep(i, 0, x - 1) cerr << d[i] << " \n"[i == x -1];
    LL ans = 0;
    rep(i, 0, x - 1) if(h >= d[i]) ans += (h - d[i]) / x + 1;
    cout << ans << '\n';
    return 0;
} 