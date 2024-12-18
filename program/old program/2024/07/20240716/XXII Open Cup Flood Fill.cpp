#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 100 + 5;
const int INF = 1e9;

int n, m, idx = 0;
string a[N], b[N];
int S = 0, T; 

namespace Flow {
    struct Edge {
        int v, nxt, val;
        Edge() {}
        Edge(int x, int y, int z) {v = x, nxt = y, val = z;}
    };
    vector<Edge> e(2);
    vector<int> head(N * N * 2), cur = head, dep = head;
    void add(int u, int v, int w) {
        e.push_back(Edge{v, head[u], w});
        head[u] = (int)e.size() - 1;
        e.push_back(Edge{u, head[v], 0});
        head[v] = (int)e.size() - 1;
    }
    int bfs() {
        queue<int> q;
        fill(dep.begin(), dep.end(), 0);
        q.push(S); dep[S] = 1;cur[S] = head[S];
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int i = head[u]; i; i = e[i].nxt) {
                int v = e[i].v;
                if(e[i].val > 0 && !dep[v]) {
                    q.push(v);
                    cur[v] = head[v];
                    dep[v] = dep[u] + 1;
                    if(v == T) return 1;
                }
            }
        }
        return dep[T];
    }

    int dfs(int u, int sum) {
        if(u == T || !sum) return sum;
        int k, res = 0;
        for(int i = cur[u]; i && sum; i = e[i].nxt) {
            int v = e[i].v;
            cur[u] = i;
            if(e[i].val > 0 && dep[v] == dep[u] + 1) {
                k = dfs(v, min(sum, e[i].val));
                if(k == 0) dep[v] = 0;
                e[i].val -= k;
                e[i^1].val += k;
                res += k;
                sum -= k;
            }
        }
        return res;
    }
    int ans = 0;
    void main() {
        while(bfs()) ans += dfs(S, INF);
        cout << ans << '\n';
    }
}


namespace init {
    int fx[] = {1, -1, 0, 0}, fy[] = {0, 0, -1, 1};
    int vis[N][N];
    int si = 0;
    set<int> G[N * N];
    int siz[N * N];
    void dfs(int x, int y, int c) {
        if(vis[x][y]) return ;
        vis[x][y] = c;
        si++;
        rep(i, 0, 3) {
            int nx = x + fx[i], ny = y + fy[i];
            if(nx < 1 || ny < 1 || nx > n || ny > m || a[x][y] != a[nx][ny]) continue;
            dfs(nx, ny, c);
        } 
    }
    void add(const int &u, const int &v) {
        G[u].insert(v), G[v].insert(u);
    }
    void main() {
        rep(i, 1, n) cin >> a[i], a[i] = " " + a[i];
        rep(i ,1, n) cin >> b[i], b[i] = " " + b[i];
        rep(i, 1, n) rep(j, 1, m) if(!vis[i][j]) si = 0, dfs(i, j, ++idx), siz[idx] = si;  //初次遍历寻找连通块
        vector<int> val(idx + 1), ty(idx + 1);
        rep(i ,1, n) rep(j, 1, m) {
            if(j < m && vis[i][j] != vis[i][j + 1]) add(vis[i][j], vis[i][j + 1]);  //连通块之间添加边，为了网络流建图做准备。
            if(i < n && vis[i][j] != vis[i + 1][j]) add(vis[i][j], vis[i + 1][j]);
            ty[vis[i][j]] = a[i][j] - '0';
        }
        rep(i ,1, n) rep(j, 1, m) if(a[i][j] != b[i][j]) val[vis[i][j]]++, Flow::ans++;
            else val[vis[i][j]]--;
        T = idx + 5;
        rep(i, 1, idx) if(val[i] > 0){
            Flow::ans -= val[i];
            if(ty[i]) {
                Flow::add(S, i, val[i]);
                for(auto j : G[i]) Flow::add(i, j, INF);
            }
            else Flow::add(i, T, val[i]);
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    init::main();
    Flow::main();
    return 0;
}
