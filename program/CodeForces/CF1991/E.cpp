#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;


void solve() {
    int n, m; cin >> n>> m;
    vector<VI> G(n + 1);
    for(int i = 1, u, v; i <= m; i++) 
        cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
    vector<int> C(n + 1);
    C[1] = 1;
    bool tag = 1;
    function<void(int)> dfs = [&](int x) {
        for(auto to : G[x]) {
            if(C[to]) {if(C[to] + C[x] != 3)tag = 0; }
            else C[to] = 3 - C[x], dfs(to);
        }
    };
    dfs(1);
    if(tag) {
        cout << "Bob" << endl;
        vector<VI> vc(3);
        rep(i ,1, n) vc[C[i]].push_back(i);
        for(int i = 1, a, b; i <= n; i++) {
            vector<int> vis(4);
            cin >> a >> b;
            vis[a] = vis[b] = 1;
            if(vis[1] && !vc[1].empty()) {
                cout << vc[1].back() << " " << 1 << endl;
                vc[1].pop_back();    
            }
            else if(vis[2] && !vc[2].empty()) {
                cout << vc[2].back() << " " << 2 << endl;
                vc[2].pop_back();
            }
            else if(!vc[1].empty()) {
                cout << vc[1].back() << " " << 3 << endl;
                vc[1].pop_back();
            }
            else {
                cout << vc[2].back() << " " << 3 << endl;
                vc[2].pop_back();
            }
        }
    }
    else {
        cout << "Alice" << endl;
        int a, b; 
        rep(i ,1, n) {
            cout << 1 << " " << 2 << endl;
            cin >> a >> b;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}