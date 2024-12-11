#include <bits/stdc++.h>

#define int int64_t

using u64 = uint64_t;
using Poly = std::vector<int>;

const int kMaxN = 805, kMod = 1e9 + 7;

int n[2], rt[2];
int cnt[kMaxN], p[kMaxN], dep[kMaxN];
bool vis[kMaxN], exi[kMaxN];
std::vector<int> T[2][kMaxN];
std::vector<std::pair<int, int>> G[2][kMaxN];

Poly mul(Poly a, Poly b) {
  Poly c(a.size() + b.size() - 1);
  for (int i = 0; i < (int)a.size(); ++i)
    for (int j = 0; j < (int)b.size(); ++j)
      c[i + j] = (c[i + j] + 1ll * a[i] * b[j] % kMod) % kMod;
  return c;
}

int calc(int n, int m) {
  Poly a(m + 1);
  for (int i = 0; i <= m; ++i)
    a[i] = exi[i];
  Poly b(m + 1);
  b[0] = 1;
  for (int i = 0; (1 << i) <= n; ++i) {
    if (n >> i & 1) {
      b = mul(b, a);
      b.resize(m + 1);
    }
    a = mul(a, a), a.resize(m + 1);
  }
  return b[m];
}

void dfs1(int o, int u, int fa) {
  cnt[u] = 0, p[u] = fa, dep[u] = dep[fa] + 1;
  for (auto v : T[o][u]) {
    dfs1(o, v, u);
    ++cnt[u];
  }
  vis[u] = (cnt[u] != 1 || u == 1);
}

void dfs2(int o, int u, int fa) {
  if (vis[u]) {
    for (int i = p[u]; i; i = p[i]) {
      if (vis[i]) {
        G[o][i].emplace_back(u, dep[u] - dep[i]);
        break;
      }
    }
  }
  for (auto v : T[o][u]) dfs2(o, v, u);
}

void work(int o) {
  dfs1(o, 1, 0), dfs2(o, 1, 0);
}

int solve(int u, int v) {
  int ret = 1;
  if (G[0][u].size() != G[1][v].size()) return 0;
  for (int i = 0; i < (int)G[0][u].size(); ++i) {
    ret = 1ll * ret * solve(G[0][u][i].first, G[1][v][i].first) % kMod;
    int cnt = G[0][u][i].second, sum = G[1][v][i].second - G[0][u][i].second;
    if (u == 1 && G[0][u].size() == 1) ++cnt;
    if (u == 0) ++sum;
    ret = 1ll * ret * calc(cnt, sum) % kMod;
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
  for (int i = 1; i <= q; ++i) {
    int op, x;
    std::cin >> op >> x;
    exi[x - 1] = 2 - op;
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
