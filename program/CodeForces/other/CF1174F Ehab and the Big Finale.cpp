#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 2e5 + 5;

int n;
vector<int> G[N];
int si[N], mx[N], rt = 1, vis[N], dis[N], pa[N];

int a1(int x) {
    cout << "d " << x << endl;
    cin >> x;
    return x;
}
 
int a2(int x) {
    cout << "s " << x << endl;
    cin >> x;
    return x;
}

void dfs(int x, int fa) {
    pa[x] = fa; si[x] = 1;
    for(auto to : G[x]) if(to != fa) 
        dis[to] = dis[x] + 1, dfs(to, x), si[x] += si[to];
}

void grt(int x, int fa, int sum) {
    si[x] = 1, mx[x] = 0;
    for(auto to : G[x]) if(to != fa && !vis[to]) {
        grt(to, x, sum) ;
        si[x] += si[to], mx[x] = max(mx[x], si[to]) ;
    }
    mx[x] = max(mx[x], sum - si[x]); 
    if(mx[x] < mx[rt]) rt = x;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1, u, v; i < n; i++) 
        cin >> u >> v, G[u].push_back(v), G[v].push_back(u) ;
    dfs(1, 0);
    mx[0] = n + 1;
    int d1 = a1(1); rt = 1;
    if(d1 == 0) return cout << "! "  << 1 << endl, 0;
    while(1) {
        int od = rt;
        grt(od, 0, si[od]);
        rt = 0;
        grt(od, 0, si[od]);
        int d = a1(rt);
        vis[rt] = 1;
        if(si[rt] == 0 || d == 0) return cout << "! "  << rt << endl, 0;
        if(d1 != dis[rt] + d) rt = pa[rt];
        else {
            if(G[rt].size() > 2) rt = a2(rt);
            else 
            for(auto to : G[rt]) if(to != pa[rt]) {
                rt = to;
                break;
            }
        }
        if(d == 1) {
            cout << "! "  << rt << endl;
            break;
        }   
    }
    return 0;
}