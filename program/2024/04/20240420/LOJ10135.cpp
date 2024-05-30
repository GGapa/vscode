// #10135. 「一本通 4.4 练习 2」祖孙询问
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 4e4 + 5;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, idx = 0, rt; cin >> n;
    vector<VI> G(N);
    VI in(N), out(N);
    for(int i = 1, u, v;  i<= n; i++)  {
        cin >> u >> v;
        if(v == -1) rt = u;
        else G[v].push_back(u), G[u].push_back(v);
    }
    function<void(int, int)> dfs = [&](int x, int pa) {
        in[x] = ++idx;
        for(auto to : G[x]) if(to != pa) {
            dfs(to, x);
        }
        out[x] = ++idx;
    };
    dfs(rt, 0);
    int q; cin >> q;
    for(int x, y; q--; ) {
        cin >> x >> y;
        if(in[x] < in[y] && out[y] < out[x]) cout << 1 << '\n';
        else if(in[y] < in[x] && out[x] < out[y])  cout << 2 << '\n';
        else cout << 0 << '\n';
    }
    return 0;
}