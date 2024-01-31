#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 100019;
int num, n, nume, cnt;

vector<int> G[maxn];

int size[maxn], wson[maxn], dep[maxn], fa[maxn], top[maxn], pos[maxn], ori[maxn];
int col[maxn];

#define ls (id << 1)
#define rs (id << 1) | 1

struct sag_tree{
    int l, r;
    int sum, c;
    int lazy; 
    int lc, rc;
} t[maxn << 2];

void build(int id, int l, int r){
    t[id].l = l;
    t[id].r = r;
    if(l == r){
        t[id].c = col[ori[l]]; 
        t[id].lc = t[id].rc = col[ori[l]]; 
        t[id].sum = 1; 
        return;
    }
    int mid = l + r >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    t[id].sum = t[ls].sum + t[rs].sum;
    if(t[ls].rc == t[rs].lc) t[id].sum -= 1;
    t[id].lc = t[ls].lc;
    t[id].rc = t[rs].rc;
}

void pushdown(int id){
    if(t[id].lazy != 0 && t[id].l != t[id].r){
        int c = t[id].lazy;
        t[ls].lazy = t[rs].lazy = c;
        t[ls].c = t[rs].c = c;
        t[ls].lc = t[ls].rc = t[rs].lc = t[rs].rc = c; 
        t[ls].sum = t[rs].sum = 1; 
        t[id].lazy = 0;
    }
}

void modify(int id, int c, int l, int r){
    pushdown(id);
    if(t[id].l == l && t[id].r == r){
        t[id].c = c;
        t[id].lazy = c;
        t[id].sum = 1;
        t[id].lc = t[id].rc = c;
        return;
    }
    int mid = t[id].l + t[id].r >> 1;
    if(mid < l){
        modify(rs, c, l, r);
    }
    else if(mid >= r){
        modify(ls, c, l, r);
    }
    else{
        modify(ls, c, l, mid);
        modify(rs, c, mid + 1, r);
    }
    t[id].sum = t[ls].sum + t[rs].sum;
    if(t[ls].rc == t[rs].lc) t[id].sum -= 1;
    t[id].lc = t[ls].lc;
    t[id].rc = t[rs].rc;
}

int query(int id, int l, int r){
    pushdown(id);
    if(t[id].l == l && t[id].r == r){
        return t[id].sum;
    }
    int mid = t[id].l + t[id].r >> 1;
    if(mid < l){
        return query(rs, l, r);
    }
    else if(mid >= r){
        return query(ls, l, r);
    }
    else{
        int ret = query(ls, l, mid) + query(rs, mid + 1, r);
        if(t[ls].rc == t[rs].lc) ret -= 1;
        return ret;
    }
}

int Qc(int id, int l, int r){
    pushdown(id);
    if(t[id].l == l && t[id].r == r){
        return t[id].c;
    }
    int mid = t[id].l + t[id].r >> 1;
    if(mid < l) return Qc(rs, l, r);
    else return Qc(ls, l, r);
}

#undef ls
#undef rs

void dfs1(int id, int F){
    size[id] = 1;
    for(auto v : G[id]){
        if(v == F) continue;
        dep[v] = dep[id] + 1;
        fa[v] = id;
        dfs1(v, id);
        size[id] += size[v];
        if(size[v] > size[wson[id]]) wson[id] = v;
    }
}

void dfs2(int id, int TP){
    top[id] = TP;
    pos[id] = ++cnt;
    ori[cnt] = id;
    if(!wson[id]) return;
    dfs2(wson[id], TP);
    for(auto v : G[id]) {
        if(v == fa[id] || v == wson[id]) continue;
        dfs2(v, v);
    }
}

void uprange(int x, int y, int c){
    while(top[x] != top[y]){
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        modify(1, c, pos[top[x]], pos[x]);
        x = fa[top[x]];
    }
    if(dep[x] > dep[y]) swap(x, y);
    modify(1, c, pos[x], pos[y]);
}

int Qsum(int x, int y){
    int ans = 0, Cson, Cfa;
    while(top[x] != top[y]){
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        ans += query(1, pos[top[x]], pos[x]);
        Cson = Qc(1, pos[top[x]], pos[top[x]]);
        Cfa = Qc(1, pos[fa[top[x]]], pos[fa[top[x]]]);
        if(Cson == Cfa) ans -= 1;
        x = fa[top[x]];
    }
    if(dep[x] > dep[y]) swap(x, y);
    ans += query(1, pos[x], pos[y]);
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> num >> n;
    for(int i = 1; i <= num; i++) cin >> col[i];
    int u, v;
    for(int i = 1; i < num; i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    build(1, 1, num);
    char ask;
    int c;
    for(int i = 1; i <= n; i++){
        cin >> ask;
        if(ask == 'Q'){
            cin >> u >> v;
            cout << Qsum(u, v) << '\n';
        }
        else{
            cin >> u >> v >> c;
            uprange(u, v, c);
        }
    }
    return 0;
}