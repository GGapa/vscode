#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e3, MOD = 1e9 + 7;

int n, n1, n2, m, q, t;
vector<int> e1[MAXN + 5], e2[MAXN + 5];

int f[MAXN + 5][MAXN + 5], g[MAXN + 5][MAXN + 5];
bool h[MAXN + 5], flag;
pair<int, int> b[MAXN + 5];

void dfs(int x1, int x2, int w1, int w2)
{
    if (e1[x2].size() == 1) dfs(e1[x1].front(), x2, w1 + 1, w2);
    else if (e2[x2].size() == 1) dfs(x1, e2[x2].front(), w1, w2 + 1);
    else
    {
        if (e1[x1].size() != e2[x2].size() || w1 > w2) return flag = true, void();
        b[++q] = make_pair(w1, w2);
        for (int i = 0; i < e1[x1].size(); i++) dfs(e1[x1][i], e2[x2][i], 1, 1);
    }
}

int main()
{
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);

    scanf("%lld%lld", &n1, &n2);
    n = max(n1, n2);
    for (int i = 2; i <= n1; i++)
    {
        static int x; scanf("%lld", &x);
        e1[x].push_back(i);
    }
    for (int i = 2; i <= n2; i++)
    {
        static int x; scanf("%lld", &x);
        e2[x].push_back(i);
    }

    scanf("%lld", &m);
    dfs(1, 1, 1, 1);

    if (flag)
    {
        for (int i = 1; i <= m; i++) puts("0");
        return 0;
    }

    for (int i = 1; i <= q; i++) t = max(t, b[i].first);
    for (int i = 1; i <= m; i++)
    {
        static int x;
        scanf("%*d%lld", &x);
        h[x] ^= 1;
        g[0][0] = 1;
        for (int j = 1; j <= t; j++)
        {
            for (int k = 0; k <= n; k++) g[j][k] = 0;
            for (int k = 1; k <= n; k++)
            {
                if (!h[k]) continue;
                for (int l = k; l <= n; l++)
                {
                    g[j][l] = (g[j][l] + g[j - 1][l - k]) % MOD;
                }
            }
        }
        int s = 1;
        for (int j = 1; j <= q; j++) s = s * g[b[j].first][b[j].second] % MOD;
        printf("%lld\n", s);
    }

    return 0;
}