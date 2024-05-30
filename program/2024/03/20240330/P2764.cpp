// 	P2764
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 200 + 5;
int n, m;
vector<VI> G;
vector<int> vis(N), mc(N);

bool dfs(int x, int tag) {
    if(vis[x] == tag) return false;
    vis[x] = tag;
    for(auto to : G[x]) if(!mc[to] || dfs(mc[to], tag)) {
        mc[to] = x;
        return 1;
    }
    return 0;
}

void out(int x) {
    cout << x << " " ;
    rep(i, 1, n) if(mc[i] == x) out(i);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    G.resize(n + 1);
    for(int i = 1, x, y; i <= m; i++) 
        cin >> x >> y, G[x].push_back(y);
    int ans = 0;
    rep(i, 1, n) if(dfs(i, i)) ans++;
    rep(i, 1, n) if(!mc[i]) out(i), cout << '\n';
    cout << n - ans << '\n';
    return 0;
}
