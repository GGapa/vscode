//PT07Z - Longest path in a tree
//https://www.spoj.com/problems/PT07Z/
//https://www.luogu.com.cn/problem/SP1437

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 100005
using namespace std;
int n, d[N] = {-1}, S1;
vector<int> G[N];

void dfs(int now, int fa)
{
    d[now] = d[fa] + 1;
    if (d[now] > d[S1])
        S1 = now;
    for (int i = 0, v; i < G[now].size(); i++)
        if ((v = G[now][i]) != fa)
            dfs(v, now);
}

int main()
{
    cin >> n;
    for (int i = 1, u, v; i < n; i++)
    {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    dfs(S1, 0);
    cout << d[S1] << endl;
    return 0;
}