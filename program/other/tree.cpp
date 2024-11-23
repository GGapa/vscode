#include <bits/stdc++.h>
using namespace std;

int n, m, tot, res[100010];

struct SegmentTree
{
    int tree[400010];
    
    void init(int x, int l, int r)
    {
        tree[x] = 0x3f3f3f3f;
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        init((x << 1), l, mid);
        init((x << 1) | 1, mid + 1, r);
    }
    
    void update(int x, int L, int R, int cl, int cr, int key)
    {
        if (cr < L || cl > R)
            return;
        if (cl >= L && cr <= R)
        {
            tree[x] = min(tree[x], key);
            return;
        }
        int mid = (cl + cr) >> 1;
        update(x << 1, L, R, cl , mid, key);
        update((x << 1) | 1, L, R, mid + 1, cr, key); 
    }
    
    void pushdown(int x, int l, int r)
    {
        if (l == r)
        {
            res[l] = tree[x];
            return;
        }
        tree[x << 1] = min(tree[x << 1], tree[x]);
        tree[(x << 1) | 1] = min(tree[(x << 1) | 1], tree[x]);
        int mid = (l + r) >> 1;
        pushdown(x << 1, l, mid);
        pushdown((x << 1) | 1, mid + 1, r); 
    }
}segtree;

struct edge
{
    int v, w, ne;
}a[400010];
bool in[400010];

int h[100010], dis1[100010], dis2[100010], link[100010], id[100010], l[100010], r[100010];
bool v[100010];

void add(int x, int y, int z)
{
    static int tmp = 0;
    a[++tmp] = (edge){y, z, h[x]};
    h[x] = tmp;
}

void dij(int *dis, int src)
{
    for (int i = 1; i <= n; i++)
    {
        dis[i] = 0x3f3f3f3f;
        v[i] = false;
    }
    dis[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >q;
    q.push(make_pair(0, src));
    while (!q.empty())
    {
        int x = q.top().second;
        q.pop();
        if (v[x])
            continue;
        v[x] = true;
        for (int i = h[x]; i != 0; i = a[i].ne)
        {
            if (v[a[i].v] == false && dis[x] + a[i].w < dis[a[i].v])
            {
                dis[a[i].v] = dis[x] + a[i].w;
                q.push(make_pair(dis[a[i].v], a[i].v));
            }
        }
    }
}

void getLink()
{
    int x = 1;
    while (x != n)
    {
        link[++tot] = x;
        id[x] = tot;
        for (int i = h[x]; i != 0; i = a[i].ne)
        {
            if (dis2[x] == dis2[a[i].v] + a[i].w)
            {
                in[i] = true;
                x = a[i].v;
                break;
            }
        }
    }
    link[++tot] = n;
    id[n] = tot;
}

void bfs(int src, int *dis, int *arr)
{
    queue<int> q;
    q.push(link[src]);
    arr[link[src]] = src;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = h[x]; i != 0; i = a[i].ne)
            if (id[a[i].v] == 0 && arr[a[i].v] == 0 && dis[x] + a[i].w == dis[a[i].v])
            {
                arr[a[i].v] = src;
                q.push(a[i].v);
            }
    }
}

int main()
{
		freopen("test.in", "r", stdin);
		freopen("test.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int x, y, z, i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
        add(y, x, z); 
    }
    dij(dis1, 1);
    dij(dis2, n);
    getLink();
    for (int i = 1; i <= tot; i++)
        bfs(i, dis1, l);
    for (int i = tot; i >= 1; i--)
        bfs(i, dis2, r);
    segtree.init(1, 1, tot);
    for (int x = 1; x <= n; x++)
        for (int i = h[x]; i != 0; i = a[i].ne)
            if (in[i] == false && l[x] > 0 && r[a[i].v] > 0 && l[x] < r[a[i].v])
                segtree.update(1, l[x], r[a[i].v] - 1, 1, tot, dis1[x] + a[i].w + dis2[a[i].v]);
    segtree.pushdown(1, 1, tot);
    int cnt = 0, ans = 0;
    for (int i = 1; i < tot; i++)
    {
        if (res[i] > ans)
        {
            ans = res[i];
            cnt = 1;
        }
        else if (res[i] == ans)
            cnt++;
    }
    if (ans == dis1[n])
        cnt = m;
    printf("%d %d\n", ans, cnt);
    return 0;
}