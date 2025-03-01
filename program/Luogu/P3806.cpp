#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 1e4 + 5;

int n, m;
vector<array<int, 2>> G[N];
int qe[N], vis[N], mx[N], si[N], st[N], dis[N];
vector<int> A(1);
int rt = 0;

void groot(int x, int fa, int sum) {
    si[x] = 1; mx[x] = 0;
    for(auto i : G[x]) {
        int to = i[0];
        if(to == fa || vis[to]) continue;
        groot(to, x, sum);
        si[x] += si[to];
        mx[x] = max(mx[x], si[to]);
    }
    mx[x] = max(mx[x], sum - si[x]);
    if(mx[x] < mx[rt]) rt = x;
}

void gdis(int x, int fa, int v, int ty) {
    A.emplace_back(x);
    st[x] = ty; dis[x] = v;
    for(auto i : G[x]) {
        int to = i[0], w =i[1];
        if(to == fa || vis[to]) continue;
        gdis(to, x, v + w, ty);
    }
}

int ok[N];

void dfs(int x) {
    vis[x] = 1;
    A.assign(1, 0);
    A.emplace_back(x); 
    dis[x] = 0; st[x] = x;
    for(auto i : G[x]) {
        int to = i[0];
        if(vis[to]) continue;
        gdis(to, x, i[1], to);
    }
    sort(A.begin() + 1, A.end(), [&](const int &x, const int &y) {
        return dis[x] < dis[y];
    });
    rep(i ,1, m) {
        int l = 1, r = (int) A.size() - 1;
        while(l < r) {
            if(dis[A[l]] + dis[A[r]] > qe[i]) r--;
            else if(dis[A[l]] + dis[A[r]] < qe[i]) l++;
            else if(st[A[l]] == st[A[r]]) {
                if(dis[A[r]] == dis[A[r - 1]]) r--;
                else l++;
            }
            else {
                ok[i] = 1;
                break;
            }
        }
    }
    for(auto i : G[x]) {
        int to = i[0];
        if(vis[to]) continue;
        rt = 0;
        groot(to, x, si[to]);
        dfs(rt);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;    
    for(int i = 1, u, v ,w; i < n; i++ )
        cin >> u >> v >> w, G[u].push_back({v, w}), G[v].push_back({u, w});
    rep(i, 1, m) cin >> qe[i];
    mx[0] = n + 1;
    groot(1, 0, n);
    dfs(rt);
    rep(i ,1, m) cout << (ok[i] ? "AYE" : "NAY") << '\n';
    return 0;
}