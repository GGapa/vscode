#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define int long long
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 1e5 + 5;

int n, m;
vector<array<int, 2>> G[N];
int A[N], vis[N], fa[N], si[N];
LL val[N];
int cnt ;
LL sum = 0, siz;

int find(int x) {
    while(x != fa[x]) fa[x] = x = fa[fa[x]];
    return x;
}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return false;
    fa[x] = y;
    si[y] += si[x]; val[y] += val[x];
    return true;
}

int size(int x) {return si[find(x)]; }
int vl(int x) {return val[find(x)]; }

void dfs(int x) {
    vis[x] = 1; siz -= A[x]; cnt--;
    for(auto i : G[x]) {
        int to = i[1], w = i[0];
        if(w < siz) continue;
        if(vis[to]) {
            if(find(x) == find(to)) continue;
            siz -= vl(to); cnt -= size(to);
        }
        else dfs(to);
        merge(x, to);
    }
}

bool check(int st) {
    cnt = n;
    fill(vis, vis + 1 + n, 0); fill(si, si + 1 + n, 1); iota(fa, fa + 1 + n, 0);
    rep(i, 1, n) val[i] = A[i];
    rep(i, 1, n) if(!vis[i]) {
        siz = st + sum, cnt = n, dfs(i);
        if(cnt == 0) return true;
    }
    return false;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, 1, n) cin >> A[i], sum += A[i];
    for(int i = 1, u, v, w; i <= m; i++) 
        cin >> u >> v >> w, G[u].push_back({w, v}), G[v].push_back({w, u});
    rep(i, 1, n) sort(G[i].begin(), G[i].end(), greater<>());
    
    int l = 1, r = 1e18, ans = -1;
    while(l <= r) {
        int mid = l + r >> 1;
        if(check(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    cout << ans << '\n';
    return 0;
}
/*
考虑反着操作，最终的大小一定是
*/