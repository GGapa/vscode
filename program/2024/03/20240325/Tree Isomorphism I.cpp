// Tree Isomorphism I 
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
map<VI, int> mp;    //不同数组的唯一编号是多少

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    
    while(T--) {
        int n; cin >> n;
        vector<VI> G(n + 1);
        auto dfs = [&](auto self, int x, int fa) -> int {
            vector<int> nm;
            for(auto to : G[x]) if(to != fa) 
                nm.push_back(self(self, to, x));
            sort(nm.begin(), nm.end());
            if(!mp.count(nm)) 
                mp[nm] = mp.size();
            return mp[nm];
        };
        for(int i = 2, x, y; i <= n; i++) 
            cin >> x >> y, G[x].push_back(y), G[y].push_back(x);
        int s1 = dfs(dfs, 1, 0);
        G.clear(); G.resize(n + 1);
        for(int i = 2, x, y; i <= n; i++) 
            cin >> x >> y, G[x].push_back(y), G[y].push_back(x);
        int s2 = dfs(dfs, 1, 0);
        cout << (s1 == s2 ? "YES\n" : "NO\n");
    }
    return 0;
}