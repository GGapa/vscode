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

constexpr int N = 1e5 + 5;

int n, q, m;
int h[N], t[N], dep[N], mn[N], cmn[N], val[N];
int fa[N][__lg(N) + 1];
vector<int> G[N], vec;

void dfs(int x, int pa, int rt) {
    // cerr << x << " " << pa << '\n';
    val[x] = t[x] + (dep[x] = dep[pa] + 1); mn[x] = x;
    vec.emplace_back(x);
    fa[x][0] = pa;
    // if(val[x] < val[cmn[rt]]) cmn[rt] = x;
    for(auto to : G[x]) if(to != pa) {
        dfs(to, x, rt);
        // mn[x] = min(mn[x], mn[to]);
        if(val[mn[to]] < val[mn[x]]) mn[x] = mn[to];
        // if(x == 1) cerr << mn[x] << '\n';
    }
}

int getanc(int x, int y) {
    per(i, __lg(n), 0) if(fa[x][i] >= y) x = fa[x][i];
    if(x > y) x = fa[x][0];
    return x;
}

signed main() {
    freopen("data.in", "r", stdin);
    freopen("user.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> q >> m;
    rep(i, 1, n) cin >> h[i];
    rep(i, 1, n) cin >> t[i];
    val[0] = t[0] = INT_MAX;

    for(int i = 1, j = 1; i <= n; i++) {
        while(j <= n && h[i] - h[j] > m) j++;
        if(i != j) G[j].emplace_back(i);
        // cerr << i << " " << j << '\n';
    }

    rep(i, 1, n) if(!dep[i]) {
        vector<int>().swap(vec);
        dfs(i, i, i); 
        sort(vec.begin(), vec.end());
        vector<int> tmp(vec.size() + 1);
        per(i, (int)vec.size() - 1, 0) {
            tmp[i] = min(tmp[i + 1], vec[i]);
            tmp[i] = (val[tmp[i + 1]] < val[vec[i]] ? tmp[i + 1] : vec[i]);
        }
        rep(i, 0, (int)vec.size() - 1) cmn[vec[i]] = tmp[i];
    }
    rep(j, 1, __lg(n)) rep(i, 1, n) fa[i][j] = fa[fa[i][j - 1]][j - 1];

    vector<int> mm(n + 1, 0); 
    rep(i, 1, n) mm[i] = t[mm[i - 1]] <= t[i] ? mm[i - 1] : i;

    for(int x, y; q--; ) {
        cin >> x >> y;
        if(x <= y) {
            cout << 1 - (x == y) << '\n';
            continue;
        }
        int ans = 1 + t[mm[y]] + (y != mm[y]), ox = x;
        ans = min(ans, t[y] + 1);
        x = getanc(x, y);
        if(x <= y) {
            ans = min(ans, val[mn[x]] - dep[x] + 1 + (mn[x] < y));
            ans = min(ans, dep[ox] - dep[x]);
        }
    
        x = cmn[y], ox = x;
        x = getanc(x, y);
        if(x <= y) {
            ans = min(ans, val[cmn[y]] - dep[x] + 1 + (cmn[y] < y));
        }
        
        cout << ans << '\n';
    }

    return 0;
}
/*
4 1 2
1 4 7 8
0 7 2 1
4 3
*/