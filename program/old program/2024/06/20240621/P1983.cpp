//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 1e3 + 5;
int G[N][N];
int F[N];
int tmp[N];
bool  use[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> in(n + 1);
    rep(i, 1, m) {
        int t; cin >> t;
        fill(use + 1, use + 1 + n, 0);
        rep(j, 1, t) cin >> tmp[j], use[tmp[j]] = 1;
        rep(j, tmp[1], tmp[t]) if(!use[j]) 
            rep(k, 1, t) if(!G[j][tmp[k]]) G[j][tmp[k]] = 1, in[tmp[k]]++;
    }
    queue<int> q;
    rep(i, 1, n) if(!in[i]) q.push({i}), F[i] = 1;
    int ans = 0;
    while(!q.empty()) {
        int x = q.front(); q.pop();
        ans = max(ans, F[x]);
        rep(i, 1, n) if(G[x][i]) if(--in[i] == 0) q.push({i}), F[i] = F[x] + 1;
    }
    cout << ans << '\n';
    return 0; 
} 
