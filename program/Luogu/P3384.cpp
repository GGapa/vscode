#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m, r, mod;
int a[N], aa[N],dep[N], size[N], top[N], hson[N], fa[N], dfn[N];
int cnt;

struct tree {
    int laz, sum;
    int l, r;
}t[N * 4];
vector<int> G[N];

#define ls (x << 1)
#define rs (x << 1 | 1)

void pushdown(int x) {      //懒标记下传出错
    if(!t[x].laz) return;    
    t[ls].sum = (t[ls].sum + t[x].laz * (t[ls].r - t[ls].l + 1) % mod) % mod;
    t[rs].sum = (t[rs].sum + t[x].laz * (t[rs].r - t[rs].l + 1) % mod) % mod;
    t[ls].laz = (t[ls].laz + t[x].laz) % mod; t[rs].laz = (t[rs].laz + t[x].laz) % mod;
    t[x].laz = 0;
}
void pushup(int x) {
    t[x].sum = (t[ls].sum + t[rs].sum) % mod;
}

void bulid(int x, int l, int r) {
    t[x].l = l; t[x].r = r;
    if(l == r) {
        t[x].sum = a[l] % mod;
        return ;
    }
    int mid = (l + r) >> 1;
    bulid(ls, l, mid);
    bulid(rs, mid + 1, r);
    pushup(x);
}

void modify(int x, int l, int r, int ch) {
    if(l <= t[x].l && t[x].r <= r) {
        t[x].laz = (t[x].laz + ch) % mod;
        t[x].sum = (t[x].sum + ch * (t[x].r - t[x].l + 1) % mod) % mod;
        return ;
    }
    pushdown(x);
    int mid = (t[x].l + t[x].r) >> 1;
    if(l <= mid) modify(ls, l, r, ch);
    if(r > mid) modify(rs, l, r, ch);
    pushup(x);
}

int qurey(int x, int l, int r) {
    if(l <= t[x].l && t[x].r <= r) {
        return t[x].sum;
    }
    pushdown(x);
    int mid = (t[x].l + t[x].r) >> 1, tmp = 0;
    if(l <= mid) tmp = (tmp + qurey(ls, l, r)) % mod;
    if(r > mid) tmp = (tmp + qurey(rs, l, r)) % mod;
    return tmp;
}

#undef ls
#undef rs

void dfs1(int x, int f) {
    dep[x] = dep[f] + 1; size[x] = 1; fa[x] = f;
    for(auto to : G[x] ) {
        if(to == f) continue;
        dfs1(to, x);
        size[x] += size[to];
        if(size[hson[x]] < size[to]) hson[x] = to;
    }
}

void dfs2(int x, int tp) {
    dfn[x] = ++cnt;
    a[cnt] = aa[x];
    top[x] = tp;
    if(!hson[x]) return;
    dfs2(hson[x], tp);
    for(auto to : G[x] ) {
        if(to == fa[x] || to == hson[x]) continue;
        dfs2(to, to);
    }
}

void mrange(int x, int y, int ch) {
    while(top[x] != top[y]) {
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        modify(1, dfn[top[x]], dfn[x], ch);
        x = fa[top[x]];
    }
    if(dep[x] > dep[y]) swap(x, y);
    modify(1, dfn[x], dfn[y], ch);
}

int qrange(int x, int y) {
    int ans = 0;
    while(top[x] != top[y])  {
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        ans = (ans + qurey(1, dfn[top[x]], dfn[x])) % mod;  //参数带错
        x = fa[top[x]];
    }
    if(dep[x] > dep[y]) swap(x, y);
    ans = (ans + qurey(1, dfn[x], dfn[y])) % mod; 
    return ans;
}


void mson(int x, int ch) {
    modify(1, dfn[x], dfn[x] + size[x] - 1, ch);
}

int qson(int x) {
   return qurey(1, dfn[x], dfn[x] + size[x] - 1) % mod;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> r >> mod;
    for(int i = 1; i <= n; i++) cin >> aa[i];
    for(int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(r, 0);
    dfs2(r, r);
    bulid(1, 1, n);
    // for(int i = 1; i <= n; i++) cout << dfn[i] << '\n';
    while(m--) {
        int op, x, y, z;
        cin >> op;
        if(op == 1) {
            cin >> x >> y >> z;
            mrange(x, y, z);
        }
        if(op == 2) {
            cin >> x >> y;
            cout << qrange(x, y) % mod<< '\n';
        }
        if(op == 3) {
            cin >> x >> z;
            mson(x, z);
        }
        if(op == 4) {
            cin >> x;

            cout << qson(x) % mod<< '\n';
        }
    }
    return 0;
}