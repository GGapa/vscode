#include <bits/stdc++.h>
namespace IO {
#define iL (1 << 20)
char ibuf[iL], *iS = ibuf + iL, *iT = ibuf + iL;
#define gc() ((iS == iT) ? (iT = (iS = ibuf) + fread(ibuf, 1, iL, stdin), iS == iT ? EOF : *iS ++) : *iS ++)
template<class T> inline void read(T &x) {
  x = 0;int f = 0;char ch = gc();
  for (; !isdigit(ch); f |= ch == '-', ch = gc());
  for (; isdigit(ch); x = (x << 1) + (x << 3) + (ch ^ 48), ch = gc());
  x = (f == 1 ? ~ x + 1 : x);
}
template<class T, class... Args> inline void read(T &x, Args&... args) { read(x), read(args...); }
template<class T> inline void readch(T &x) { char ch = gc(); for (; !isalpha(ch); ch = gc()); x = ch; }
char Out[iL], *iter = Out;
#define flush() fwrite(Out, 1, iter - Out, stdout), iter = Out
template<class T> inline void write(T x, char ch = '\n') {
  T l, c[35];
  if (x < 0) *iter ++ = '-', x = ~ x + 1;
  for (l = 0; !l || x; c[l] = x % 10, l++, x /= 10);
  for (; l; -- l, *iter ++ = c[l] + '0');*iter ++ = ch;
  flush();
}
template<class T, class... Args> inline void write(T x, Args... args) { write(x, ' '), write(args...); }
} // IO
using namespace IO;
#define N 805
#define ll long long
#define DEBUG0
#define pii pair<int, int>
#define fi first
#define se second
#define vi vector<int>
#define MOD 1000000007
#define pb push_back
#define il inline
using namespace std;
il int pls(int x, int y) { return x + y >= MOD ? x + y - MOD : x + y; }
il int sub(int x, int y) { return x - y < 0 ? x - y + MOD : x - y; }
il int prd(int x, int y) { return (1ll * x * y % MOD); }

int n1, n2, Q; set<int> Len;
vi G1[N], G2[N]; 
int d1[N], d2[N], l1[N], l2[N];
int cnt; pii len[N];

il void dfs1(int x) {
  for (auto y : G1[x]) dfs1(y);
  if (G1[x].size() > 1 || G1[x].empty()) d1[x] = 1, l1[x] = x;
  else d1[x] = d1[G1[x][0]] + 1, l1[x] = l1[G1[x][0]];
}
il void dfs2(int x) {
  for (auto y : G2[x]) dfs2(y);
  if (G2[x].size() > 1 || G2[x].empty()) d2[x] = 1, l2[x] = x;
  else d2[x] = d2[G2[x][0]] + 1, l2[x] = l2[G2[x][0]];
}
int FL = 1;
il void dfs3(int x, int y) {
  len[++ cnt] = {d1[x], d2[y]};
  x = l1[x], y = l2[y];
  if (G1[x].size() != G2[y].size()) { FL = 0; return ; }
  for (int i = 0; i < G1[x].size(); i++) {
    dfs3(G1[x][i], G2[y][i]);
  }
}

int dp[N][N];
int tot, lk[N];
int main() {
// #ifndef ONLINE_JUDGE
  // freopen("test.in", "r", stdin); freopen("test.out", "w", stdout);
// #endif
  freopen("b.in", "r", stdin); freopen("b.out", "w", stdout);
  read(n1, n2);
  for (int i = 2, x; i <= n1; i++) read(x), G1[x].pb(i);
  for (int i = 2, x; i <= n2; i++) read(x), G2[x].pb(i);
  dfs1(1), dfs2(1), dfs3(1, 1); 

  int mx1 = 0, mx2 = 0;
  for (int i = 1; i <= cnt; i++) 
    mx1 = max(mx1, len[i].fi), mx2 = max(mx2, len[i].se);

  read(Q);
  for (int _ = 1, op, x; _ <= Q; _++) {
    read(op, x);
    if (op == 1) Len.insert(x);
    else Len.erase(x);
    if (!FL) { write(0); continue; }
    tot = 0; for (int u : Len) lk[++ tot] = u;
    dp[0][0] = 1;
    for (int i = 1; i <= mx1; i++) {
      for (int j = 0; j <= mx2; j++) dp[i][j] = 0;
      for (int p = 1; p <= tot; p++) for (int j = lk[p]; j <= n2; j++) {
        dp[i][j] = pls(dp[i][j], dp[i - 1][j - lk[p]]);
      }
    }
    int ans = 1;
    for (int i = 1; i <= cnt; i++) 
      ans = prd(ans, dp[len[i].fi][len[i].se]);
    write(ans);
  }
  // printf("%.4lf", 1.0 * clock() / CLOCKS_PER_SEC);
  return 0;
}