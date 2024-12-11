#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 2e5 + 5;
const int mod = 998244353;

vector<int> G[N];
int vis[N];
LL pw[N];
int cnt[2];

bool dfs(int x, int fa) {
    bool ret = false; vis[x] = 1;
    cnt[0]++; cnt[1] += G[x].size();
    for(auto to : G[x]) if(to != fa) {
        if(to == x) ret = true;
        else if(!vis[to]) ret |= dfs(to, x);
    }
    return ret;
}

void solve() {
    int n; cin >> n;
    rep(i, 0, n) vector<int>(0).swap(G[i]), vis[i] = 0;
    vector<int> A(n + 1), B(n + 1) ;
    rep(i, 1, n) cin >> A[i]; rep(i, 1, n) cin >> B[i];
    rep(i, 1, n) G[A[i]].emplace_back(B[i]), G[B[i]].emplace_back(A[i]);
    LL ans = 1;
    rep(i, 1, n) if(!vis[i]){
        cnt[0] = cnt[1] = 0;
        if(dfs(i, 0)) (ans *= n) %= mod;
        else (ans *= 2) %= mod;
        if(cnt[0] * 2 != cnt[1]) return cout << 0 << '\n', void();
    }
    cout << ans << '\n', void();
}
 
void init() {
    pw[0] = 1;
    rep(i, 1, N - 1) pw[i] = pw[i - 1] * 2 % mod;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    init();
    cin >> T;
    while(T--) solve();
    return 0;
}