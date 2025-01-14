#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for (int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define il inline
#define re register
#define ll long long
#define ull unsigned ll
#define pii pair<int, int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 2500 + 5;


int n, m;
bool e[N][N], X[N], Y[N], u[N * 2];
vector<pii> E, Ans;
vector<int> P;
il void dfs(int x, int fa)
{
    if (u[x])
        return;
    u[x] = 1, P.eb(x);
    if (fa)
        E.eb(x, fa);
    if (x <= n)
    {
        for (re int i = 1; i <= m; ++i)
            if (e[x][i] && i + n != fa)
                dfs(i + n, x);
    }
    else
    {
        for (re int i = 1; i <= n; ++i)
            if (e[i][x - n] && i != fa)
                dfs(i, x);
    }
}
vector<int> g[N * 2];
int deg[N * 2];
il void add(int x, int y)
{
    g[x].eb(y), g[y].eb(x), ++deg[x], ++deg[y];
}
vector<pii> las;
il void solve(int x)
{
    // cerr << "solve = " << x << "\n";
    vector<pii>().swap(E), vector<int>().swap(P), dfs(x, 0);
    for (auto t : E)
        add(t.fi, t.se) /*, cerr << t.fi << " " << t.se << "\n"*/;
    queue<int> Q;
    for (auto x : P)
        if (deg[x] == 1)
            Q.emplace(x);
    for (re int i = 0; i + 2 < P.size(); ++i)
    {
        x = Q.front();
        Q.pop();
        for (auto y : g[x])
        {
            if (--deg[y] >= 1)
                Ans.eb(x, y);
            if (deg[y] == 1)
                Q.emplace(y);
        }
    }
    x = Q.front(), Q.pop();
    int y = Q.front();
    if (x > y)
        swap(x, y);
    las.eb(x, y);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (re int i = 1; i <= n; ++i)
    {
        string str;
        cin >> str;
        for (re int j = 1; j <= m; ++j)
            if (str[j - 1] == 'R')
                e[i][j] = X[i] = Y[j] = 1;
    }
    int A = 0, B = 0, K = 0;
    for (re int i = 1; i <= n; ++i)
        if (X[i])
            ++A;
    for (re int i = 1; i <= m; ++i)
        if (Y[i])
            ++B;
    for (re int i = 1; i <= n; ++i)
        if (X[i] && !u[i])
            ++K, solve(i);
    int dL = n * m - (n - (A - K)) * (m - B), dR = n * m - (n - A) * (m - (B - K)), ans = max(dL, dR);
    if (ans == dL)
        for (auto &t : las)
            swap(t.fi, t.se);
    for (auto t : las)
        Ans.eb(t);
    cout << Ans.size() << "\n";
    for (auto t : Ans)
    {
        if (t.fi < t.se)
            cout << "X " << t.fi << " " << t.se - n << "\n";
        else
            cout << "Y " << t.se << " " << t.fi - n << "\n";
    }

    return 0;
}