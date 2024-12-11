// Subtree
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
// #define int long long
const int N = 1e5 + 5;

int mod;
vector<int> G[N];
vector<ll> pre[N], suf[N], D, F;

ll dpD(int x, int fa = -1) {
    ll &d = D[x];
    d = 1;
    for(auto to : G[x]) if(to != fa) 
        (d *= dpD(to, x)) %= mod;
    (d += 1) %= mod;
    
    int n = G[x].size();
    auto &p = pre[x], &s = suf[x];
    p.resize(n + 3, 1), s.resize(n + 3, 1);
    rep(i, 1, n) {
        int to = G[x][i - 1] ;
        p[i] = p[i - 1];
        if(to != fa) (p[i] *= D[to]) %= mod;
    }
    per(i, n, 1) {
        int to = G[x][i - 1];
        s[i] = s[i + 1];
        if(to != fa) (s[i] *= D[to]) %= mod;
    }
    return d;
}
void dpF(int x, int fa = -1) {
    int n = G[x].size();
    rep(i, 1, n) {
        int to = G[x][i - 1];
        if(to == fa) continue;
        F[to] = (1 + F[x] * pre[x][i - 1] % mod * suf[x][i + 1] % mod) % mod;
        // cout << pre[x][i - 1] << " " << suf[x][i + 1] << '\n';
        dpF(to, x);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n >> mod;
    D.resize(n + 1), F.resize(n + 1);
    for(int i = 2, x, y; i <= n; i++) 
        cin >> x >> y, G[x].push_back(y), G[y].push_back(x);
    dpD(1); F[1] = 1;
    dpF(1);
    // rep(i, 1, n) cout << F[i] % mod << '\n';
    rep(i, 1, n) cout << (D[i] - 1 + mod) % mod * F[i] % mod  << '\n';
    return 0;
}