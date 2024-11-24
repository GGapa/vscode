#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define CSP2024 GG BUT I WILL WIN NOIP2024
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 80000 + 5;

int n, m;

vector<int> G[N];
set<int> c[N];
set<array<int, 3>> s;
int fa[17][N];
int A[N], B[N], C[N], D[N], ans[N], siz[N];

void add(int u, int v) {
    fa[0][u] = v;
    rep(i, 1, 16) fa[i][u] = fa[i - 1][fa[i - 1][u]];
    G[v].emplace_back(u);
}

void dfs(int x, int fa) {
    siz[x] = c[x].size();
    for(auto to : G[x]) if(to != fa) {
        dfs(to, x);
        if(c[to].size() > c[x].size()) swap(c[x], c[to]), swap(siz[x], siz[to]);
        for(auto cc : c[to]) if(!c[x].count(cc)) c[x].insert(cc), siz[x]++;
    }
    ans[x] = siz[x];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    vector<array<int, 5>> op;   // x, l, r, id, tp
    using AI = array<int, 5>;
    for(int i = 1, a, b, c, d; i <= n; i++) {
        cin >> a >> b >> c >> d;
        op.push_back({a, b, d, i, 1});
        op.push_back({c, b, d, i, -1});
        A[i] = a, B[i] = b, C[i] = c, D[i] = d;
    }
    for(int i = 1, a, b, c; i <= m; i++) {
        cin >> a >> b >> c;
        op.push_back({a, b, c, i, 0});
    }
    sort(op.begin(), op.end(), [&](const AI &x, const AI &y) {
        return (x[0] == y[0] ? x[4] > y[4] : x[0] < y[0]); 
    });
    for(auto t : op) {
         if(t[4] == 1) {
            auto it = s.lower_bound({t[1], 0, 0});
            if(it != s.begin()) {   
                int x = (*prev(it))[2];
                if(D[x] > t[2]) add(t[3], x);
                else {
                    per(i, 16, 0) if(fa[i][x] && D[fa[i][x]] < t[2]) x = fa[i][x];
                    x = fa[0][x];
                    if(x) add(t[3], x);
                }
            }
            s.insert({t[1], t[2], t[3]});
        }
        else if(t[4] == -1) s.erase({t[1], t[2], t[3]});
        else {
            auto it = s.lower_bound({t[1] + 1, 0, 0});
            if(it != s.begin()) {   
                int x = (*prev(it))[2];
                if(D[x] >= t[1]) c[x].insert(t[2]);
                else {
                    per(i, 16, 0) if(fa[i][x] && D[fa[i][x]] < t[1]) {
                        x = fa[i][x];
                    }
                    x = fa[0][x];
                    if(x) c[x].insert(t[2]);
                }
            }
        }
    }   
    rep(i, 1, n) if(!fa[0][i]) dfs(i, 0);
    rep(i, 1, n) cout << ans[i] << "\n";
    return 0;
}