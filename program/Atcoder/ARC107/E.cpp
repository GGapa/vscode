#include <bits/stdc++.h>
#define For(i, x, y) for (register int i = (x); i <= (y); i++)
#define FOR(i, x, y) for (register int i = (x); i < (y); i++)
#define Dow(i, x, y) for (register int i = (x); i >= (y); i--)
#define Debug(v)            \
    for (auto i : v)        \
        printf("%lld ", i); \
    puts("")
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define fil(a, b) memset((a), (b), sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pa;
typedef pair<ll, ll> PA;
typedef vector<int> poly;
inline ll read()
{
    ll x = 0, f = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && (c != '-'))
        c = getchar();
    if (c == '-')
        f = -1, c = getchar();
    while (c >= '0' && c <= '9')
        x = x * 10 + c - '0', c = getchar();
    return x * f;
}

const int N = 5e5 + 10, M = 20;
int n, a[N], b[N], f[M + 1][N], g[N][M + 1];
ll cnt[6];

int vis[N];
inline int mex(int a, int b)
{
    vis[a] = vis[b] = 1;
    For(i, 0, 2) if (!vis[i]) return vis[a] = vis[b] = 0, i;
}

int main()
{
    n = read();
    For(i, 1, n) a[i] = read(), f[1][i] = a[i];
    For(i, 2, n) b[i] = read();
    if (n <= M)
    {
        For(i, 2, n)
        {
            f[i][1] = b[i];
            For(j, 2, n) f[i][j] = mex(f[i - 1][j], f[i][j - 1]);
        }
        For(i, 1, n) For(j, 1, n) cnt[f[i][j]]++;
        For(i, 0, 2) printf("%d ", cnt[i]);
        return 0;
    }
    For(i, 2, M)
    {
        f[i][1] = b[i];
        For(j, 2, n) f[i][j] = mex(f[i - 1][j], f[i][j - 1]);
    }
    For(i, 1, M)
    {
        For(j, 1, n) cnt[f[i][j]]++;
        For(j, 1, M) g[i][j] = f[i][j];
    }
    For(i, M, n) cnt[f[M][i]] += min(n - M, n - i);
    int tot = 0;
    For(i, M + 1, n)
    {
        g[i][1] = b[i], cnt[g[i][1]]++;
        For(j, 2, M) g[i][j] = mex(g[i - 1][j], g[i][j - 1]), cnt[g[i][j]]++, ++tot;
        cnt[g[i][M]] += n - i, tot += n - i;
    }
    For(i, 0, 2) printf("%lld ", cnt[i]);
    puts("");
}
