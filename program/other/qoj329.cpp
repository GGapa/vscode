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

constexpr int N = 3e4 + 5;

int n, m, rt; 
int sz[N], mx[N], vis[N], st[N], dis[N], qe[N], ok[N];
vector<AI<2>> G[N];

void grt(int x, int fa, int siz) {
    sz[x] = 1, mx[x] = 0;
    for(auto [to, w] : G[x]) if(to != fa && !vis[to]) {
        grt(to, x, siz);
        sz[x] += sz[to];
        mx[x] = max(mx[x], sz[to]);
    }
    mx[x] = max(mx[x], siz - sz[x]);
    if(mx[rt] > mx[x]) rt = x;
}

vector<int> A;

void gdis(int x, int fa, int tag) {
    sz[x] = 1;
    A.emplace_back(x);
    st[x] = tag;
    for(auto [to, w] : G[x]) if(to != fa && !vis[to]){
        dis[to] = dis[x] + w;
        gdis(to, x, tag);
        sz[x] += sz[to];
    }
}

void work(int x) {
    // cerr << x << '\n';
    vis[x] = 1;
    vector<int>(1).swap(A);
    A.emplace_back(x);
    dis[x] = 0; st[x] = x;
    for(auto [to, w] : G[x]) if(!vis[to]){
        dis[to] = w; 
        gdis(to, x, to);
    }
    sort(A.begin() + 1, A.end(), [&](const int x, const int y) {
        return dis[x] < dis[y];
    }); 
    rep(i, 1, m) {
        int l = 1, r = (int)A.size() - 1;
        while(l < r) {
            // cerr << l << " " << r << '\n';
            if(dis[A[l]] + dis[A[r]] > qe[i]) r--;
            else if(dis[A[l]] + dis[A[r]] < qe[i]) l++;
            else if(st[A[l]] == st[A[r]]) {
                if(dis[A[l]] == dis[A[r - 1]]) r--;
                else l++;
            }
            else {
                ok[i] = 1;
                break;
            }
        }
    }
    for(auto [to, w] : G[x]) if(!vis[to]){
        rt = 0;
        // cerr << x << " nxt: " << to << " " << sz[to] << " rt: ";
        grt(to, x, sz[to]); 
        // cerr << rt <<       " " << mx[rt] << " " << sz[rt] << '\n';
        work(rt);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for(int i = 1, u, v, w; i < n; i++) 
        cin >> u >> v >> w, G[u].push_back({v, w}), G[v].push_back({u, w});
    rep(i, 1, m) cin >> qe[i];
    mx[0] = n + 1;
    grt(1, 0, n);
    work(rt);
    rep(i, 1, m) cout << (ok[i] ? "Yes" : "No") << '\n';
    return 0;
}