#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define int long long 
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 2e5 + 5;

vector<int> G[N];
int l[N], r[N], ans;
LL si[N];

void dfs(int x, int fa) {
    for(auto to : G[x]) if(to != fa) dfs(to,x ), si[x] += si[to];
    if(si[x] < l[x]) ans++, si[x] = r[x]; 
    si[x] = min(si[x], 1ll * r[x]);
}

void solve() {
    int n; cin >> n;
    rep(i, 1, n) vector<int>(0).swap(G[i]);
    memset(si, 0, sizeof(si));

    for(int i = 2, x; i <= n; i++) 
        cin >> x, G[x].emplace_back(i), G[i].emplace_back(x);

    rep(i, 1, n) cin >> l[i] >> r[i];
    ans = 0;

    dfs(1, 0);

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}