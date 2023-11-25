//P3379 【模板】最近公共祖先（LCA）
//https://www.luogu.com.cn/problem/P3379
// 重链剖分LCA
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 500000 + 5;
int n,m,s;
vector <int> vec[maxn];
int fa[maxn], siz[maxn], dep[maxn], hson[maxn];
int top[maxn];

inline int read()
{
    char c;
    int f = 1, x = 0;
    c = getchar();
    while(!isdigit(c))
    {
        if(c=='-')f=-1;
        c = getchar();
    }
    while(isdigit(c))
    {
        x = (x * 10) + (c - '0');
        c = getchar();
    }
    return x;
}
void dfs1(int x, int f)//第一趟dfs，先得到每个节点的fa（父节点）、sz（子树大小）、dep（深度）、hson（重子节点）
{
    fa[x] = f;
    dep[x] = dep[f] + 1;
    siz[x] = 1;
    for(auto to : vec[x])
    {
        if(to == f) continue;
        dfs1(to, x);
        siz[x] += siz[to];
        if(siz[to] > siz[hson[x]]) hson[x] = to;
    }
}

void dfs2(int x,int tp)//第二趟dfs，得到每个节点的top（链头，即所在的重链中深度最小的那个节点）：
{
    top[x] = tp;
    if(!hson[x]) return;
    dfs2(hson[x], tp);
    for(auto to : vec[x])
    {
        if(to == fa[x] || to == hson[x]) continue;
        dfs2(to ,to);
    }
}


int LCA(int x, int y)
{
    while(top[x] != top[y])
    {
        if(dep[top[x]] < dep[top[y]])swap(x,y);
        x = fa[top[x]];
    }
    if(dep[x] < dep[y])return x;
    return y;
}

int main()
{
    n = read();
    m = read();
    s = read();
    for(int i = 1, x, y; i < n ; i++)
    {
        x = read();
        y = read();
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    dfs1(s, 0);
    dfs2(s, s);
    for(int i = 1, x, y; i <= m; i++)
    {
        x = read();
        y = read();
        cout << LCA(x, y) << "\n";
    }
    return 0;
}