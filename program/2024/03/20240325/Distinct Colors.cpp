// Distinct Colors
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<int> A(n + 1), ans(n + 1);
    vector<vector<int>> G(n + 1);
    rep(i, 1, n) {cin >> A[i];}
    for(int i = 2, x, y; i <= n; i++) 
        cin >> x >> y, G[x].push_back(y), G[y].push_back(x);
    vector<set<int>> s(n + 1);
    auto dfs = [&](auto self, int x, int fa) -> void{
        // set<int> s;
        s[x].insert(A[x]);
        for(auto to : G[x]) if(to != fa) {
            self(self, to, x);
            if(s[x].size() < s[to].size()) swap(s[x], s[to]);
            for(auto i : s[to]) s[x].insert(i);
        }
        ans[x] =  s[x].size();
        // return s;
    };
    // set<int> s;
    dfs(dfs, 1, 0);
    rep(i, 1, n) cout << ans[i] << " \n"[i == n];

    return 0;
}