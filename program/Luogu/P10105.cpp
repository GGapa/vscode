#include <bits/stdc++.h>
// #include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
// using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<int, siz>;

constexpr int N = 2e5 + 5, LG = __lg(N) + 1;

int n, rt = 0;
int vis[N], dep[N], pre[N], mx[N];
int tr[N][LG];
vector<int> G[N], D[N]; 

void dfs(int x, int fa) {
    dep[x] = dep[fa] + 1; pre[x] = fa;
    if(dep[x] > dep[rt]) rt = x;
    for(auto to : G[x]) if(to != fa && !vis[to]) 
        dfs(to, x);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i = 1, u, v; i < n; i++) 
        cin >> u >> v, G[u].emplace_back(v), G[v].emplace_back(u);
  
    dfs(1, 0);
    dfs(rt, 0);
    for(; rt; rt = pre[rt]) D[0].emplace_back(rt), vis[rt] = 1;
    int len = D[0].size();
    D[0].insert(D[0].begin(), 0);
    rep(i, 1, (int)len) {
        rt = 0; dep[0] = -1;
        tr[i + 1][0] = i;
        dfs(D[0][i], 0);
        mx[i] = max(mx[i], dep[rt]);
        for(; rt != D[0][i]; rt = pre[rt]) vis[rt] = 1, D[i].emplace_back(rt);
        D[i].emplace_back(rt);
        reverse(D[i].begin(), D[i].end());
    }

    rep(j, 1, __lg(len)) for(int i = 1; i + (1 << j) - 1 <= len; i++)
        tr[i][j] = mx[tr[i][j - 1]] < mx[tr[i + (1 << j - 1)][j - 1]] ? tr[i][j - 1] : tr[i + (1 << j - 1)][j - 1];
    // rep(i, 1, len) rep(j, 0, __lg(len)) cout << tr[i][j] << " \n"[j == __lg(len)];

    auto query = [&](int l, int r) {
        int d = __lg(r - l + 1);
        return (mx[tr[l][d]] > mx[tr[r - (1 << d) + 1][d]]) ? tr[l][d] : tr[r - (1 << d) + 1][d];
    };  

    int q; cin >> q;
    while(q--) {
        vector<int> vec(4), id(4);
        rep(i, 1, 3) cin >> vec[i], id[i] = i;
        sort(id.begin() + 1, id.end(), [&](const int x, const int y) {
            return vec[x] >  vec[y];
        });
        int u, v, w;
        int dis1 = (vec[id[2]] - vec[id[3]] + vec[id[1]]) / 2, dis2 = vec[id[1]] - dis1;
        int tmp = query(dis1 + 1, len - dis2);
        if (mx[tmp] >= vec[id[2]] - dis1) {
            u = D[0][tmp - dis1]; v = D[0][tmp + dis2];
            w = D[tmp][vec[id[2]] - dis1];
        }
        else {
            tmp = query(dis2 + 1, len - dis1);
            u = D[0][tmp + dis1]; v = D[0][tmp - dis2];
            w = D[tmp][vec[id[2]] - dis1];
        } 
        if (id[1] == 1 && id[2] == 2) cout << u << " " << v << " " << w << "\n";
        if (id[1] == 1 && id[2] == 3) cout << v << " " << u << " " << w << "\n";
        if (id[1] == 2 && id[2] == 1) cout << u << " " << w << " " << v << "\n";
        if (id[1] == 2 && id[2] == 3) cout << v << " " << w << " " << u << "\n";
        if (id[1] == 3 && id[2] == 1) cout << w << " " << u << " " << v << "\n";
        if (id[1] == 3 && id[2] == 2) cout << w << " " << v << " " << u << "\n";
    }

    return 0;
}
/*
First find two max distance and the id. need only down and up. 
DP on tree
*/