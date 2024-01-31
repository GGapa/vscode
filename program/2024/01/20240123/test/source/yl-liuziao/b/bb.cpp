#include <bits/stdc++.h>

#define int int64_t

using u64 = uint64_t;

const int kMaxN = 805, kMod = 1e9 + 7;

int n[2], cc[2], rt[2];
int cnt[kMaxN], p[kMaxN], dep[kMaxN], f[kMaxN][kMaxN];
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

void prework() {
  std::fill_n(f[0], n[1] + 1, 0);
  f[0][0] = 1;
  for (int i = 1; i <= n[1]; ++i) {
    for (int j = 0; j <= n[1]; ++j) {
      f[i][j] = 0;
      for (int k = 0; k <= j; ++k)
        if (exi[k])
          f[i][j] = (f[i][j] + f[i - 1][j - k]) % kMod;
    }
  }
}

void work(int o) {
  dfs1(o, 1, 0), dfs2(o, 1, 0);
}

void gethash(int o, int u) {
  hs[u] = 1;
  int cnt = 3;
  for (auto p : G[o][u]) {
    int v = p.first;
    gethash(o, v);
    hs[u] *= (hs[v] + (++cnt));
  }
}

int solve(int u, int v) {
  int ret = 1;
  if (G[0][u].size() != G[1][v].size()) return 0;
  for (int i = 0; i < G[0][u].size(); ++i) {
    ret = 1ll * ret * solve(G[0][u][i].first, G[1][v][i].first) % kMod * f[G[0][u][i].second + (u == 1 && G[0][u].size() == 1)][G[1][v][i].second - (u != 0) * G[0][u][i].second] % kMod;
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
    gethash(o, 1);
  }
  rt[0] = 1;
  if (G[0][1].size() != G[1][1].size()) {
    rt[0] = 0, G[0][0].emplace_back(1, 1);
    gethash(0, 0);
  }
  int q;
  std::cin >> q;
  for (int i = 1; i <= q; ++i) {
    std::cerr << i << '\n';
    int op, x;
    std::cin >> op >> x;
    exi[x - 1] = 2 - op;
    prework();
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
