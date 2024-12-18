#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define int long long
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    const LL INF = 1e18;
    vector<LL> F(n * 2 + 1 + m), si(n * 2 + 1 + m), A(n + 1);
    rep(i, 1, n) cin >> A[i], si[i] = A[i], F[i] = INF;
    int rt = n;
    vector<int> fa(n * 2 + 1 + m); iota(fa.begin(), fa.end(), 0);
    auto find = [&](int x) {
        while(fa[x] != x) x = fa[x] = fa[fa[x]];
        return x;
    };
    vector<array<int, 3>> E;
    for(int i = 1, u, v, w; i <= m; i++) 
        cin >> u >> v >> w, E.push_back({w, u, v});
    sort(E.begin(), E.end(), greater<>());
    
    for(auto e : E) {
        int x = e[1], y = e[2], w = e[0];
        int sx = find(x), sy = find(y) ;
        if(sx == sy) continue;
        fa[sx] = fa[sy] = ++rt;
        F[rt] = max(min(1ll * w - si[sx], F[sy] - si[sx]), min(1ll * w - si[sy], F[sx] - si[sy]));
        si[rt] = si[sx] + si[sy];
    }        
    cout << (F[rt] > 0 ? F[rt] : -1) << '\n';
    return 0;
}