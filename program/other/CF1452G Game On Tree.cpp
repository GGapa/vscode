#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 2e5 + 5;

int n, k;

vector<int> G[N];
int a[N], sz[N], mx[N], vis[N], si[N];
int rt;

void grt(int x, int fa, int sum) {
    sz[x] = 1; mx[x] = 0;
    for(auto to : G[x]) if(to != fa && !vis[to])  {
        grt(to, x, sum);
        sz[x] += sz[to];
        mx[x] = max(mx[x], sz[to]);
    }
    mx[x] = max(mx[x], sum - mx[x]);
    if(mx[x] < mx[rt]) rt = x;
}

int cnt[N], ans[N];

void get(int x, int fa, int dis, int sz) {
    if(a[x] > dis) cnt[min(sz, a[x] - dis - 1)] = max(cnt[min(sz, a[x] - dis - 1)], a[x]);
    for(auto to : G[x]) if(to != fa && !vis[to]) 
        get(to, x, dis + 1, sz);
}

void update(int x, int fa, int dis) {
    ans[x] = max(ans[x], cnt[dis]); si[x] = 1;
    for(auto to : G[x]) if(to != fa && !vis[to]) {
        update(to, x, dis + 1);
        si[x] += si[to];
    }
}

void dfs(int x, int sz) {   
    vis[x] = 1;
    fill(cnt, cnt + 2 + sz, 0);
    get(x, 0, 0, sz);
    per(i, sz - 1, 0) cnt[i] = max(cnt[i], cnt[i + 1]);
    update(x, 0, 0);
    for(auto to : G[x]) if(!vis[to]) {
        rt = 0; grt(to, x, si[to]);
        dfs(rt, si[to]);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1, u, v; i < n; i++)
        cin >> u >> v, G[u].emplace_back(v), G[v].emplace_back(u);
        
    cin >> k;
    queue<int> q;
    memset(a, -1, sizeof(a));
    for(int i = 1, x; i <= k; i++)
        cin >> x, q.push(x), a[x] = 0;
    
    while(!q.empty()) {
        int x = q.front(); q.pop();
        for(auto to : G[x]) if(a[to] == -1) {
            a[to] = a[x] + 1;
            q.push(to);
        }
    }

    mx[0] = n + 1; rt = 0;  
    grt(1, 0, n);
    dfs(rt, n);

    rep(i, 1, n) cout << (a[i] == 0 ? 0 : ans[i]) << ' ';
    return 0; 
}
/*
对于一个起始点 u 如果能够走到 v 则满足
a[v] >= dis(u, v)
有理由利用点分治，对于每个分治中心。
dis[u] <= a[v] - dis[v]
*/