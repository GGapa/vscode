// Finding a Centroid
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int >;
vector<VI> G;
int ans = -1;
int n;
int dfs(int x, int fa = -1) {
    int s = 1, nv = -1;
    for(auto to : G[x]) if(to != fa) {
        int vs = dfs(to, x);
        s += vs, nv = max(vs, nv);
    }
    nv = max(nv, n - s);
    if(nv <= n / 2 && ans == -1) ans = x;
    return s; 
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n; G.resize(n + 1);
    for(int i = 2, a, b; i <= n; i++) {
        cin >> a >> b;
        G[a].push_back(b), G[b].push_back(a);
    }
    dfs(1);
    cout << ans << '\n';
    return 0;
}