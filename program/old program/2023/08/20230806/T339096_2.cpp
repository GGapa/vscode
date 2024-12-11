#include <iostream>
#include <limits.h>
#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 20000 + 5;
const int maxm = 40000 + 5;
struct Edge
{
    int to, dis, next, monster, dep = 1;
};
Edge edge[maxm];
int head[maxn], dis[maxn], it;
bool bj[maxn];
int n, m, s, t;
inline void add_edge(int u, int v, int d)
{
    it++;
    // edge[it].dis = d;
    edge[it].to = v;
    edge[it].next = head[u];
    edge[it].monster = d;
    head[u] = it;
}
struct Node
{
    int dis;
    int pos;
    bool operator<(const Node &x) const
    {
        return x.dis < dis;
    }
};
/*
void dfs(int x, int de)
{
    for (int i = head[x]; i; i = edge[i].next)
    {
        if(edge[i].dep < de) continue;
        edge[i].dep = de;
        edge[i].dis = edge[i].monster / de;
        dfs(edge[i].to, de + 1);
    }
}
*/
priority_queue<Node> que;

inline void dijstra()
{
    dis[t] = 0;
    que.push((Node){0, t});
    while (!que.empty())
    {
        Node tmp = que.top();
        que.pop();
        int x = tmp.pos, d = tmp.dis;
        if (bj[x])
            continue;
        bj[x] = true;
        for (int i = head[x]; i; i = edge[i].next)
        {
            int y = edge[i].to;
            edge[y].dep = edge[i].dep + 1;
            edge[i].dis = edge[i].monster / edge[i].dep;
            if (dis[y] > dis[x] + edge[i].dis)
            {
                dis[y] = dis[x] + edge[i].dis;
                if (!bj[y])
                    que.push((Node){dis[y], y});
            }
        }
    }
}

signed main()
{
    cin >> n >> m >> s >> t;
    for (int i = 1, u, v, w; i <= m; i++)
    {
        cin >> u >> v >> w;
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    for (int i = 1; i <= n; i++)
        dis[i] = INT_MAX;
    //dfs(t, 1);
    dijstra();
    cout << dis[s] << endl;
    return 0;
}