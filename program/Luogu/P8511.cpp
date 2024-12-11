#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 5e5 + 5;

int n; 
vector<int> G[N];
LL A[N];
int fa[N];

struct Trie {
    LL ans = 0;
    pair<int, int> bst;
    int tr[N * 61][2], rec[N * 61], idx = 0; 
    void clear() {
        rep(i, 0, idx) tr[i][0] = tr[i][1] = 0;
        ans = idx = 0;
        bst = {0, 0};
    }
    void update(int id) {
        LL x = A[id], it = 0;
        per(i, 61, 0) {
            int t = x >> i & 1; t ^= 1;
            auto &tt = tr[it][t];
            if(tt) it = tt;
            else it = tr[it][t^1];
        }
        int i = id, j = rec[it];
        LL ret = A[i] ^ A[j];
        if(ret >= ans) ans = ret, bst = {i, j} ;
    }
    void insert(int id) {
        LL x = A[id], it = 0;
        per(i, 61, 0) {
            int t = x >> i & 1;
            auto &tt = tr[it][t];
            if(!tt) tt = ++idx;
            it = tt;
        }
        rec[it] = id;
        update(id) ;
    };
}T;

int vis[N];
LL ans[N];

void ins(int x) {
    T.insert(x) ;
    for(auto to : G[x]) ins(to) ;
};

void dfs(int x) {
    ans[x] = T.ans;
    T.insert(x);
    for(auto to : G[x]) if(!vis[to]) ins(to) ;
    for(auto to : G[x]) if(vis[to])  dfs(to) ;
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 2; i <= n; i++) 
        cin >> fa[i], G[fa[i]].emplace_back(i) ;
    rep(i, 1, n) cin >> A[i], T.insert(i);

    int x = T.bst.first, y = T.bst.second;
    LL t = T.ans;

    T.clear();
    for(int i = x; i != 0; i = fa[i]) vis[i] = 1;
    dfs(1) ;

    fill(vis, vis + 1 + n, 0);
    T.clear();
    for(int i = y; i != 0; i = fa[i]) vis[i] = 1;
    dfs(1);
    for(int i = x; i != 0; i = fa[i]) vis[i] = 1;
    rep(i, 1, n) if(!vis[i]) ans[i] = t;

    rep(i, 1, n) cout << ans[i] << '\n';
    return 0; 
}