#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 2e5 + 5;

int n, m, d; 
vector<int> G[N], T[N];
int vis[N];
int num = 0;

void dfs(int x) {
    vis[x] = 1; num++;
    for(auto to : T[x]) if(!vis[to])
        dfs(to);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> d;
    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v, G[u].emplace_back(v), G[v].emplace_back(u);
        if(u == 1 || v == 1) continue;
        T[u].emplace_back(v), T[v].emplace_back(u);
    }
    int cnt = 0;
    vector<array<int, 2>> sc;
    for(auto i : G[1]) if(!vis[i]) {
        num = 0;
        cnt++, dfs(i); 
        sc.push_back({num, i});
    }
    if(G[1].size() < d || cnt > d) return cout << "NO\n", 0;
    cout << "YES\n";
    queue<int> q;
    fill(vis, vis + 1 + n, 0);
    sort(sc.begin(), sc.end());
    for(auto a : sc) {
        int i = a[1] ;
        if(q.size() >= d) break;
        cout << 1 << " " << i << '\n';
        q.push(i); vis[i] = 1;
    }
    for(auto i : G[1]) {
        if(q.size() >= d) break;
        if(vis[i]) continue;
        cout << 1 << " " << i << '\n', q.push(i), vis[i] = 1;
    }
    vis[1] = 1;
    while(!q.empty()) {
        int x = q.front(); q.pop();
        for(auto to : G[x]) if(!vis[to]) {
            vis[to] = 1;
            q.push(to);
            cout << x << " " << to << '\n';
        }
    }
    return 0;
}