// P1197 [JSOI2008] 星球大战
#include <iostream>
using namespace std;
const int maxn = 4e5 + 1;
int n, m, k, it;
int f[maxn];
int head[maxn];
int fail[maxn];
int fight[maxn];
int ans[maxn];
int find(int x)
{
    if (x != f[x])
        f[x] = find(f[x]);
    return f[x];
}
struct Edge
{
    int from, to, next;
} map[maxn];

void insert(int x, int y)
{
    map[it].from = x;
    map[it].next = head[x];
    map[it].to = y;
    head[x] = it;
    it++;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
        head[i] = -1;
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        x++;
        y++;
        insert(x, y);
        insert(y, x);
    }
    cin >> k;
    int alive = n - k;
    for (int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        x++;
        fail[x] = true;
        fight[i] = x;
    }
    for (int i = 1; i <= 2 * m; i++)
    {
        if (!fail[map[i].from] && !fail[map[i].to])
        {
            if (find(map[i].from) != find(map[i].to))
            {
                alive--;
                f[find(map[i].from)] = f[find(map[i].to)];
            }
        }
    }
    ans[k + 1] = alive;
    for (int i = k; i >= 1; i--)
    {
        int tmp = fight[i];
        alive++;
        fail[tmp] = false;
        for (int j = head[tmp]; j != -1; j = map[j].next)
        {
            if (!fail[map[j].to] && f[find(tmp)] != f[find(map[j].to)])
            {
                alive--;
                f[find(map[j].to)] = f[find(tmp)];
            }
        }
        ans[i] += alive;
    }
    for (int i = 1; i <= k + 1; i++)
        cout << ans[i] << endl;
    return 0;
}