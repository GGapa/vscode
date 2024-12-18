#include <bits/stdc++.h>
using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__)

using LL = long long;
using ULL = unsigned long long;
const int N = 800 + 5;
const int Mod = 1e9 + 7;

inline int qp(int a, int b = Mod - 2) {
  int res = 1;
  while (b) {
    if (b & 1) res = LL(res) * a % Mod;
    a = LL(a) * a % Mod;
    b /= 2;
  }
  return res;
}

int fac[N], ifac[N];
inline void InitComb(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = LL(fac[i - 1]) * i % Mod;
  ifac[n] = qp(fac[n]);
  for (int i = n; i; --i) ifac[i - 1] = LL(ifac[i]) * i % Mod; 
}

struct Tree {
  int n, sz, bel[N], fa[N], cnt[N], vis[N], pa[N];
  vector<int> G[N], nG[N];
  void build() {
    for (int i = 2; i <= n; ++i) cin >> fa[i], G[fa[i]].push_back(i);
    for (int u = 1; u <= n; ++u) {
      if (vis[u]) continue;
      vis[u] = 1, bel[u] = ++sz, cnt[sz] = 1;
      int v = u;
      while (G[v].size() == 1) {
        v = G[v][0];
        bel[v] = sz, vis[v] = 1, ++cnt[sz];
      }
      pa[sz] = bel[fa[u]];
      nG[bel[fa[u]]].push_back(sz);
    }
  }
} T1, T2;
int to[N], ok = 1, mx1 = 0, mx2 = 0;
void dfs(int u1, int u2) {
  if (T1.nG[u1].size() != T2.nG[u2].size()) ok = 0;
  to[u1] = u2;
  if (T1.cnt[u1] > T2.cnt[u2]) ok = 0;
  mx1 = max(mx1, int(T1.cnt[u1]));
  mx2 = max(mx2, int(T2.cnt[u2]));
  for (int i = 0; i < T1.nG[u1].size(); ++i) {
    int v1 = T1.nG[u1][i];
    int v2 = T2.nG[u2][i];
    dfs(v1, v2);
  }
}
int qn, ans[N], f[N][N], g[105][N][N];

ULL val[N];
mt19937_64 rnd(time(0));

int main() {
  freopen("b.in", "r", stdin);
  freopen("b.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  InitComb(N - 5);
  cin >> T1.n >> T2.n, T1.build(), T2.build();
  dfs(1, 1);
  cin >> qn;
  if (!ok) {
    cerr << "!!\n";
    while (qn--) cout << 0 << "\n";
    return 0;
  }
  for (int i = 1; i <= max(T1.n, T2.n); ++i) val[i] = rnd();
  map<ULL, int> Ans; ULL now = 0;
  f[0][0] = 1;
  for (int t = 1; t <= qn; ++t) {
    int op, u; cin >> op >> u;
    now ^= val[u];
    if (Ans.count(now)) {
      int id = Ans[now];
      for (int i = 0; i <= mx1; ++i) {
        for (int j = i; j <= mx2; ++j) f[i][j] = g[id][i][j];
      }
      cout << ans[id] << "\n";
    } else {
      Ans[now] = t;
      if (op == 1) {
        for (int i = mx1; i >= 0; --i) {
          for (int k = 1; k <= i; ++k) {
            int lim = max(i, i - k + k * u);
            for (int j = mx2; j >= lim; --j) {
              f[i][j] = (f[i][j] + LL(f[i - k][j - k * u]) * ifac[k]) % Mod;
            }
          }
        }
      } else {
        for (int i = 0; i <= mx1; ++i) {
          for (int k = 1; k <= i; ++k) {
            int lim = max(i, i - k + k * u);
            for (int j = mx2; j >= lim; --j) {
              f[i][j] = (f[i][j] + Mod - LL(f[i - k][j - k * u]) * ifac[k] % Mod) % Mod;
            }
          }
        }
      }
      for (int i = 0; i <= mx1; ++i)
        for (int j = i; j <= mx2; ++j) g[t][i][j] = f[i][j];
      int res = 1;
      for (int i = 1; i <= T1.sz; ++i) {
        res = LL(res) * f[T1.cnt[i]][T2.cnt[to[i]]] % Mod * fac[T1.cnt[i]] % Mod;
      }
      cout << (ans[t] = res) << "\n";
    }
  }
  return 0;
}