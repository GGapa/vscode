// P3379 【模板】最近公共祖先（LCA）
// https://www.luogu.com.cn/problem/P3379
// 2023-11-09 20:41
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 500000 + 5;

int n, m, s; 
vector<int> G[maxn];
int si[maxn], top[maxn], hson[maxn], fa[maxn], dep[maxn];


void dfs1(int x, int f) {
    si[x] = 1; dep[x] = dep[f] + 1; fa[x] = f;
    for(auto to : G[x]) {
        if(to == f) continue;
        dfs1(to, x);
        si[x] += si[to];
        if(si[to] > si[hson[x]]) hson[x] = to;
    }
}

void dfs2(int x, int tp) {
    top[x] = tp;
    if(!hson[x]) return ;
    dfs2(hson[x], tp);
    for(auto to : G[x]) {
        if(to == fa[x] || to == hson[x]) continue;
         dfs2(to, to);       
    }
}

int lca(int x, int y) {
    while(top[x] != top[y]) {
        if(dep[top[x]] < dep[top[y]]) swap(x, y);   
        x = fa[top[x]];
    }
    return (dep[x] < dep[y] ? x : y);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("AKIOI.in", "r", stdin);
    // freopen("AKIOI.out", "w", stdout);
    cin >> n >> m >> s;
    for(int i = 1, u, v; i < n; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(s, 0);
    dfs2(s, s);
    while(m--) {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << "\n";
    }
    return 0;
}


/*
编程语言
C++14 (GCC 9)
代码长度
1.37KB
用时
1.86s
内存
55.85MB
 GGapa

所属题目
P3379 【模板】最近公共祖先（LCA）
评测状态
Accepted
评测分数
100
提交时间
2023-11-09 21:04:30
*/