// Tree Diameter
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
vector<VI> G;

int ans = 0;
int dfs(int x, int fa = -1) {
    vector<int> F;
    for(auto to : G[x]) if(to != fa)
       F.push_back(dfs(to, x) + 1);
    if(F.empty()) return 0;
    sort(F.begin(), F.end(), greater<>());
    ans = max(ans, ((int)F.size() > 1 ? F[0] + F[1] : F[0]));
    return F[0];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n; G.resize(n + 1);
    for(int i = 2, a, b; i<= n; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1);
    cout << ans << '\n';
    return 0;
}