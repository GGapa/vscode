#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 2e5 + 5;

vector<int> G[N];

int dep[N], mx, cnt = 0, fa[N];
int n, m; 

void dfs(int x) {
    if(G[x].empty()) dep[x] = 0;
    for(auto to : G[x]) {
        dfs(to);
        if(x != 1 && dep[to] + 1 >= mx) cnt++;
        else dep[x] = max(dep[to] + 1, dep[x]) ;
    }
}

bool check(int x) {
    mx = x, cnt = 0; fill(dep, dep + 1 + n, 0) ;
    dfs(1) ;
    return cnt <= m; 
}

void solve() {
    cin >> n >> m;
    rep(i, 0, n) G[i].clear();
    
    fa[1] = 1;
    for(int i = 2, x; i <= n; i++)
        cin >> fa[i], G[fa[i]].emplace_back(i) ;

    int l = 1, r = n, ans;
    while(l <= r) {
        int mid = l + r >> 1;
        if(check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
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
/*
1
4 2
1 2 3 4
*/