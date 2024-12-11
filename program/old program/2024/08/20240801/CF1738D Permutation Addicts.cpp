#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 1e5 + 5;
int n;
vector<int> G[N];

void dfs(int x) {
    if(x && x != n + 1) cout << x << " ";
    for(auto to : G[x]) if(G[to].empty()) cout << to << " ";
    for(auto to : G[x]) if(!G[to].empty()) dfs(to);
}

void solve() {
    cin >> n;
    int mn = 0;
    rep(i, 0, n + 1) vector<int>(0).swap(G[i]);
    int rt = 1;
    for(int i = 1, x; i <= n; i++) {
        cin >> x;
        if(!x || x == n + 1) rt = x;
        G[x].push_back(i);
        mn = max(mn, min(i, x)) ;
    }
    cout << mn << '\n';
    dfs(rt);
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}