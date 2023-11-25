// P3379 【模板】最近公共祖先（LCA）
// https://www.luogu.com.cn/problem/P3379
// 倍增法求解
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 500000 + 5;
const int maxk = 21; // log2(maxn) + 1

int fa[maxk][maxn];
int depth[maxn];
vector<int> vec[maxn];

void dfs(int x, int f)
{
    fa[0][x] = f;
    depth[x] = depth[f] + 1;
    for (int i = 1; i < maxk; i++)
    {
        fa[i][x] = fa[i - 1][fa[i - 1][x]];
    }
    for (auto to : vec[x])
    {
        if (to == f)
            continue;
        dfs(to, x);
    }
}

int LCA(int x, int y)
{
    if (depth[x] < depth[y])
        swap(x, y);
    for (int i = maxk - 1; i >= 0; i--)
    {
        if (depth[fa[i][x]] >= depth[y])
            x = fa[i][x];
    }
    if (x == y)
        return x;
    for (int i = maxk - 1; i >= 0; i--)
    {
        if (fa[i][x] != fa[i][y])
        {
            x = fa[i][x];
            y = fa[i][y];
        }
    }
    return fa[0][x];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, s;
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1, x, y; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    dfs(s, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        cout << LCA(a, b) << endl;
    }
    return 0;
}
