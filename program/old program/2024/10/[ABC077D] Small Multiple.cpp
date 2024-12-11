// cao,,没想到这辈子 Dijkstra 还能够写挂
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 1e5 + 5;
const LL  inf = 1e18;

vector<pair<int, int>> G[N];


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int x; cin >> x;
    rep(i, 0, x - 1) rep(j, 0, 9) G[i].emplace_back((i * 10 + j) % x, j); 
    rep(i, 1, 9) G[x].emplace_back(i % x, i);
 
    priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> q;
    vector<LL> d(x * 10  + 1, inf);
    q.push({0, x}); d[x] = 0; 
    while(!q.empty()) { 
        int xx = q.top().second, vv = q.top().first;  q.pop();
        if(d[xx] < vv) continue;
        for(auto to : G[xx]) if(d[to.first] > d[xx] + to.second) d[to.first] = d[xx] + to.second, q.push({d[to.first], to.first});
    }
    cout << d[0] << '\n';
    return 0;
}