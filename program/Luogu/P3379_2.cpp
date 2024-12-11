// P3379 【模板】最近公共祖先（LCA）
// https://www.luogu.com.cn/problem/P3379
// 2023-11-09 21:40
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 500000 + 5;

int n, m, s;
vector<int> G[maxn];
int dfn[maxn], mi[20][maxn];

int get(int x, int y) {
    return dfn[x] < dfn[y] ? x : y;
}

void dfs(int x, int f) {
    dfn[x] = ++dfn[0]; mi[0][dfn[x]] = f;
    for(auto to : G[x]) if(to != f) dfs(to, x);
}

int lca(int x, int y) {
    if(x == y) return x;
    if((x = dfn[x]) > (y = dfn[y])) swap(x, y);
    int d = log2(y - x++);
    return get(mi[d][x], mi[d][y - (1 << d) + 1]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("AKIOI.in", "r", stdin);
    // freopen("AKIOI.out", "w", stdout);
    cin >> n >> m >> s;
    for(int i = 1, u, v; i < n; i++)  {
        cin >> u >> v;
        G[u].push_back(v); G[v].push_back(u);
    }
    dfs(s, 0);
    for(int i = 1; i <= log2(n); i++) for(int j = 1; j + (1 << i) - 1 <= n; j++) 
        mi[i][j] = get(mi[i - 1][j], mi[i - 1][j + (1 << i - 1)]);
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
1.25KB
用时
1.64s
内存
77.61MB
GGapa

所属题目
P3379 【模板】最近公共祖先（LCA）
评测状态
Accepted
评测分数
100
提交时间
2023-11-09 22:02:41
*/