#include <bits/stdc++.h>

#define int int64_t

using u64 = uint64_t;

const int kMaxN = 805, kMod = 1e9 + 7;

int n[2], cc[2], rt[2];
int cnt[kMaxN], p[kMaxN], dep[kMaxN];
int fac[kMaxN], ifac[kMaxN], inv[kMaxN], f[kMaxN][kMaxN];
u64 hs[kMaxN];
bool vis[kMaxN], exi[kMaxN];
std::vector<int> T[2][kMaxN];
std::vector<std::pair<int, int>> G[2][kMaxN];

void dfs1(int o, int u, int fa) {
  cnt[u] = 0, p[u] = fa, dep[u] = dep[fa] + 1;
  for (auto v : T[o][u]) {
    dfs1(o, v, u);
    ++cnt[u];
  }
  vis[u] = (cnt[u] != 1 || u == 1);
  cc[o] += vis[u];
}

void dfs2(int o, int u, int fa) {
  if (vis[u]) {
    bool fl = 0;
    for (int i = p[u]; i; i = p[i]) {
      if (vis[i]) {
        G[o][i].emplace_back(u, dep[u] - dep[i]);
        fl = 1;
        break;
      }
    }
    assert(fl || u == 1);
  }
  for (auto v : T[o][u]) dfs2(o, v, u);
}

void work(int o) {
  dfs1(o, 1, 0), dfs2(o, 1, 0);
}

int C(int m, int n) {
  if (m < n || m < 0 || n < 0) return 0;
  return 1ll * fac[m] * ifac[n] % kMod * ifac[m - n] % kMod;
}

void prework() {
  fac[0] = ifac[0] = fac[1] = ifac[1] = inv[1] = 1;
  for (int i = 1; i <= 800; ++i) {
    inv[i] = 1ll * (kMod - kMod / i) * inv[kMod % i] % kMod;
    fac[i] = 1ll * i * fac[i - 1] % kMod;
    ifac[i] = 1ll * inv[i] * ifac[i - 1] % kMod;
  }
}

void add(int x) {
  for (int i = n[1]; ~i; --i) {
    for (int j = i; j; --j) {
      int lim = j;
      if (x) lim = std::min(lim, i / x);
      for (int k = 1; k <= lim; ++k)
        f[i][j] = (f[i][j] + 1ll * f[i - k * x][j - k] * C(j, k) % kMod) % kMod;
    }
  }
}

void del(int x) {
  for (int i = 1; i <= n[1]; ++i) {
    for (int j = 1; j <= i; ++j) {
      int lim = j;
      if (x) lim = std::min(lim, i / x);
      for (int k = 1; k <= lim; ++k)
        f[i][j] = (f[i][j] - 1ll * f[i - k * x][j - k] * C(j, k) % kMod + kMod) % kMod;
    }
  }
}

int solve(int u, int v) {
  int ret = 1;
  if (G[0][u].size() != G[1][v].size()) return 0;
  for (int i = 0; i < G[0][u].size(); ++i) {
    ret = 1ll * ret * solve(G[0][u][i].first, G[1][v][i].first) % kMod;
    int cnt = G[0][u][i].second, sum = G[1][v][i].second - G[0][u][i].second;
    if (u == 1 && G[0][u].size() == 1) ++cnt;
    if (u == 0) ++sum;
    ret = 1ll * ret * f[cnt][sum] % kMod;
  }
  return ret;
}

void dickdreamer() {
  std::cin >> n[0] >> n[1];
  for (int o = 0; o <= 1; ++o) {
    for (int i = 2; i <= n[o]; ++i) {
      int fa;
      std::cin >> fa;
      T[o][fa].emplace_back(i);
    }
    work(o);
  }
  rt[0] = 1;
  if (G[0][1].size() != G[1][1].size()) {
    rt[0] = 0, G[0][0].emplace_back(1, 1);
  }
  int q;
  std::cin >> q;
  prework();
  f[0][0] = 1;
  for (int i = 1; i <= q; ++i) {
    std::cerr << i << '\n';
    int op, x;
    std::cin >> op >> x;
    if (op == 1) add(x - 1);
    else del(x - 1);
    std::cerr << "!!!\n";
    std::cout << solve(rt[0], 1) << '\n';
  }
}

int32_t main() {
  freopen("b.in", "r", stdin);
  freopen("b.out", "w", stdout);
  std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
  int T = 1;
  // std::cin >> T;
  while (T--) dickdreamer();
  // std::cerr << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
  return 0;
}
