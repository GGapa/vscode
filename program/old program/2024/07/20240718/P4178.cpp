#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 4e4 + 5;
 
int n, m;
vector<array<int, 2>> G[N];
int vis[N], mx[N], si[N];
int rt = 0;
vector<int> dis(1);

void groot(int x, int fa, int sum) {
    si[x] = 1; mx[x] = 0;
    for(auto i : G[x]) {
        int to = i[0];
        if(to == fa || vis[to]) continue;
        groot(to, x, sum);
        si[x] += si[to];
        mx[x] = max(mx[x], si[to]);
    }
    mx[x] = max(mx[x], sum - si[x]);
    if(mx[x] < mx[rt]) rt = x;
}

void gdis(int x, int fa, int v) {
    dis.emplace_back(v);
    for(auto i : G[x]) {
        int to = i[0];
        if(vis[to] || fa == to) continue;
        gdis(to, x, v + i[1]);
    }
}

int work(int x, int w) {
    int ans = 0; dis.assign(1, 0);
    gdis(x, 0, w);
    sort(dis.begin() + 1, dis.end()) ;
    int l = 1, r = (int)dis.size() - 1;
    while(l <= r) (dis[l] + dis[r] <= m) ? (ans += r - l, ++l) : (r--);
    return ans;   
}

int ans = 0;

void dfs(int x) {
    vis[x] = 1; ans += work(x, 0);
    for(auto i: G[x]) {
        int to = i[0] ;
        if(vis[to]) continue;
        ans -= work(to, i[1]);
        mx[0] = n, rt = 0; 
        groot(to, x, si[to]);
        dfs(rt);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1, u, v ,w; i < n; i++ )
        cin >> u >> v >> w, G[u].push_back({v, w}), G[v].push_back({u, w});
    cin >> m;
    mx[0] = n, rt = 0; 
    groot(1, 0, n);
    dfs(1);
    cout << ans << '\n';
    return 0;
}