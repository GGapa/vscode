#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
#define int long long
using LL = long long;
using VI = vector<int>;

struct DSU {
    vector<int> fa;
    int n; 
    DSU(int _n) : n(_n), fa(_n + 1) {iota(fa.begin(), fa.end(), 0);}
    void init() {iota(fa.begin(), fa.end(), 0);}
    int find(int x) {
        while(x != fa[x]) x = fa[x] = fa[fa[x]];
        return x;
    }
    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        return fa[x] = y, true;
    }
}; 

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    using AI = array<int, 3>;
    vector<array<int, 3>> edge;
    for(int i = 1, u, v, w; i <= m; i++) 
        cin >> u >> v >> w, edge.push_back({w, u, v}) ;
    int p, k, a, b, c; cin >> p >> k >> a >> b >> c;
    vector<int> q(k + 1);
    rep(i, 1, p) cin >> q[i];
    rep(i, p + 1, k) q[i] = 1ll * (q[i - 1] * a + b) % c;

    sort(edge.begin(), edge.end());
    sort(q.begin() + 1, q.end());
    
    vector<int> e(1);
    rep(i ,0, m - 1) rep(j, i, m - 1) e.push_back((edge[i][0] + edge[j][0] + 1) / 2);
    sort(e.begin(), e.end());

    LL ans = 0, sum = 0, cnt = 0;
    DSU g(n);

    for(int i = 1, j = 0; i <= k; i++) {
        int oj = j;
        while(j < (int)e.size() && e[j] <= q[i]) j++;
        if(oj != j) {
            sort(edge.begin(), edge.end(), [&](const AI &a, const AI &b) {
                int x = abs(e[j - 1] - a[0]), y = abs(e[j - 1] - b[0]);
                if(x != y) return x < y;
                return a[0] > b[0];
            });
            cnt = sum = 0;
            g.init();
            rep(i, 0, m - 1) if(g.merge(edge[i][1], edge[i][2])) {
                if(edge[i][0] > e[j - 1]) sum += edge[i][0], cnt--;
                else sum -= edge[i][0], cnt++;
            }
        } 
        // cout << i << " " << j << " " << q[i] << " " << cnt * q[i] + sum << '\n';
        ans ^= cnt * q[i] + sum;
    }
    cout << ans << '\n';
    return 0;
}