#include <iostream>
#include <algorithm>
#include <vector>

typedef long long ll;
typedef double lf;

// #define DEBUG 1
struct IO
{
    #define MAXSIZE (1 << 20)
    #define isdigit(x) (x >= '0' && x <= '9')
    char buf[MAXSIZE], *p1, *p2;
    char pbuf[MAXSIZE], *pp;
    #if DEBUG
    #else
    IO() : p1(buf), p2(buf), pp(pbuf) {}
    ~IO() {fwrite(pbuf, 1, pp - pbuf, stdout);}
    #endif
    #define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2) ? ' ' : *p1++)
    #define blank(x) (x == ' ' || x == '\n' || x == '\r' || x == '\t')

    template <typename T>
    void Read(T &x)
    {
        #if DEBUG
        std::cin >> x;
        #else
        bool sign = 0; char ch = gc(); x = 0;
        for (; !isdigit(ch); ch = gc())
            if (ch == '-') sign = 1;
        for (; isdigit(ch); ch = gc()) x = x * 10 + (ch ^ 48);
        if (sign) x = -x;
        #endif
    }
    void Read(char *s)
    {
        #if DEBUG
        std::cin >> s;
        #else
        char ch = gc();
        for (; blank(ch); ch = gc());
        for (; !blank(ch); ch = gc()) *s++ = ch;
        *s = 0;
        #endif
    }
    void Read(char &c) {for (c = gc(); blank(c); c = gc());}

    void Push(const char &c)
    {
        #if DEBUG
        putchar(c);
        #else
        if (pp - pbuf == MAXSIZE) fwrite(pbuf, 1, MAXSIZE, stdout), pp = pbuf;
        *pp++ = c;
        #endif
    }
    template <typename T>
    void Write(T x)
    {
        if (x < 0) x = -x, Push('-');
        static T sta[35];
        int top = 0;
        do sta[top++] = x % 10, x /= 10; while (x);
        while (top) Push(sta[--top] ^ 48);
    }
    template <typename T>
    void Write(T x, char lst) {Write(x), Push(lst);}
} IO;
#define Read(x) IO.Read(x)
#define Write(x, y) IO.Write(x, y)
#define Put(x) IO.Push(x)

using namespace std;

const int MAXN = 810, mod = 1e9 + 7;

int n1, n2, q, fa1[MAXN], fa2[MAXN];
vector <int> e1[MAXN], e2[MAXN];
vector <pair <int, int> > qry;

int dep1[MAXN], dep2[MAXN];
int DFS2(int u)
{
    if (!e2[u].size() || e2[u].size() > 1) return u;
    dep2[e2[u][0]] = dep2[u] + 1;
    return DFS2(e2[u][0]);
}
bool flag, flag2;
void DFS1(int u, int top, int rt)
{
    if (flag) return;
    if (e1[u].size() != 1)
    {
        dep2[rt] = 1; int btm = DFS2(rt);
        int x = dep1[u] - dep1[top] + 1, y = dep2[btm] - dep2[rt] + 1;
        if (x > y) {flag = 1; return;}
        else if (x == y) flag2 = 1;
        else qry.emplace_back(x, y);
        if (e2[btm].size() != e1[u].size()) {flag = 1; return;}
        for (int i = 0; i < e1[u].size() && !flag; i++)
            dep1[e1[u][i]] = dep1[u] + 1, DFS1(e1[u][i], e1[u][i], e2[btm][i]);
        return;
    }
    dep1[e1[u][0]] = dep1[u] + 1;
    DFS1(e1[u][0], top, rt);
}

ll f[MAXN][MAXN];
int st[MAXN], top; bool avl[MAXN];

// #include <ctime>

int main()
{
    // int start = clock();
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    #if DEBUG
    #else
    ios::sync_with_stdio(0), cin.tie(0);
    #endif
    Read(n1), Read(n2);
    for (int i = 2; i <= n1; i++) Read(fa1[i]), e1[fa1[i]].push_back(i);
    for (int i = 2; i <= n2; i++) Read(fa2[i]), e2[fa2[i]].push_back(i);
    dep1[1] = 1, DFS1(1, 1, 1);
    // cout << "\n";
    // for (auto x : qry) cout << x.first << " " << x.second << "\n";

    // cerr << 1.0 * (clock() - start) / CLOCKS_PER_SEC << "\n";
    Read(q);
    int op, x, mxq = 0, mxc = 0, mxt = 0;
    for (auto x : qry) mxq = max(mxq, x.first), mxc = max(mxc, x.second), mxt = max(mxt, x.second - x.first + 1);
    // cerr << mxq << " " << mxc << "\n";
    f[0][0] = 1;
    while (q--)
    {
        Read(op), Read(x);
        if (flag) {cout << "0\n"; continue;}
        if (op == 1) avl[x] = 1;
        else avl[x] = 0;
        if (flag2 && !avl[1]) {cout << "0\n"; continue;}

        top = 0;
        int mx = 0, lmt;
        for (int i = 1; i <= mxt; i++) if (avl[i]) st[++top] = mx = i;
        for (int i = 1; i <= mxq; i++)
        {
            int lmt = min(i * mx, min(mxc, i + mxt));
            for (int j = i; j <= lmt; j++) f[i][j] = 0;
            for (int j = 1; j <= top; j++)
                for (int k = lmt, p = st[j]; k >= p && k >= i; k--)
                    f[i][k] += f[i - 1][k - p];
            if (i % 4 == 0)
                for (int j = i; j <= lmt; j++) f[i][j] %= mod;
        }

        ll ans = 1;
        for (auto x : qry)
        {
            if (f[x.first][x.second] > mod) f[x.first][x.second] %= mod;
            ans = ans * f[x.first][x.second] % mod;
        }
        cout << ans << "\n";
    }
    // cerr << 1.0 * (clock() - start) / CLOCKS_PER_SEC << "\n";
    return 0;
}