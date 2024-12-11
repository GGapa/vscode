// P4185 [USACO18JAN] MooTube G
// https://www.luogu.com.cn/problem/P4185
// 2023-11-6 20:30
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;

int n, q;
struct Node1 {
    int u, v, w;
}G[maxn];
struct Node2 {   
    int id, k, v;
}op[maxn];
int siz[maxn], ans[maxn], fa[maxn];

int find(int x) {
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("AKIOI.in", "r", stddin);
    // freopen("AKIOI.out", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n + 1; i++) fa[i] = i, siz[i] = 1;
    for(int i = 1, u, v, w; i < n; i++) {
        cin >> G[i].u >> G[i].v >> G[i].w;
    }
    for(int i = 1, u, v; i <= q; i++) {
        cin >> op[i].k >> op[i].v;
        op[i].id = i;
    }

    sort(G + 1, G + n, [](const Node1& x, const Node1& y) {return x.w > y.w;});
    sort(op + 1, op + 1 + q, [](const Node2& x, const Node2& y){return x.k > y.k;});
    int it = 1;
    for(int i = 1; i <= q; i++) {
        while(it <= n && G[it].w >= op[i].k) {
            int t1 = find(G[it].u), t2 = find(G[it].v);
            fa[t2] = t1;
            siz[t1] += siz[t2];
            it++;
        }
        ans[op[i].id] = siz[find(op[i].v)];
    }
    for(int i = 1; i <= q; i++) {
        cout << ans[i] - 1<< "\n";
    }
    return 0;
}
/*
编程语言
C++14 (GCC 9)
代码长度
1.42KB
用时
336ms
内存
3.88MB
 GGapa

所属题目
P4185 [USACO18JAN] MooTube G
评测状态
Accepted
评测分数
100
提交时间
2023-11-06 21:02:33
*/