//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;


void solve() {
    int n, m ; cin >> n >> m;
    vector<VI> G(n + 1);
    for(int i = 1, u, v; i <= m; i++) 
        cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
    vector<int> st; 
    rep(i, 1, n) if(G[i].size() >= 4) st.push_back(i);
    vector<int> path; vector<int> vis(n + 1);
    int S; bool tag = false;
    function<void(int, int)> dfs = [&](int x, int fa) {
        if(tag) return ;
        if(vis[x])  {
            if(x == S) {
                vector<int> tmp;
                bool che = 0;
                for(auto to : G[S]) if(vis[to] != 1) tmp.push_back(to);
                if(tmp.size() >= 2) {
                    cout << "YES\n";
                    vector<array<int, 2>> ans;
                    rep(i, 0, 1) ans.push_back({S, tmp[i]});
                    for(int i = 0; i + 1 < path.size(); i++) ans.push_back({path[i], path[i + 1]}); 
                    ans.push_back({path.back(), S});
                    cout << ans.size() << "\n"; 
                    for(auto a : ans) cout << a[0] << " " << a[1] << '\n';
                    tag = 1;
                    return ;
                }
            }
            return ;
        }
        vis[x] = 1;
        path.push_back(x);
        for(auto to : G[x]) if(to != fa) dfs(to, x);
        path.pop_back();
        vis[x] = 2;
    };
    for(auto s : st) {
        S = s; tag = false;
        vector<int>(0).swap(path);
        fill(vis.begin(), vis.end(), 0);
        dfs(s, 0);
        if(tag == 1) break;
    }
    if(!tag) cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve(); 
    return 0;
}
