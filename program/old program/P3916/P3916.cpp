// P3916 图的遍历
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define maxn 100010

int n, m, used[maxn];
vector<int> map[maxn];

void dfs(int x, int d)
{
    if (used[x])
        return;
    used[x] = d;
    for (int i = 0; i < map[x].size(); i++)
        dfs(map[x][i], d);
}

int main()
{
    int u, v;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        map[v].push_back(u);
    }
    for (int i = n; i; i--)
        dfs(i, i);
    for (int i = 1; i <= n; i++)
        printf("%d ", used[i]);
    printf("\n");
    return 0;
}