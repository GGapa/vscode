#include <bits/stdc++.h>

#define int int64_t

using u64 = uint64_t;

const int kMaxN = 5e3 + 5, kMaxM = 1e5 + 5, kMod = 998244353;

int n, m, t;
int a[kMaxN];

int qpow(int bs, int idx = kMod - 2) {
  int ret = 1;
  for (; idx; idx >>= 1, bs = 1ll * bs * bs % kMod)
    if (idx & 1)
      ret = 1ll * ret * bs % kMod;
  return ret;
}

namespace Sub1 {
int cnt, now[15], cc[kMaxN][15], w[kMaxN][kMaxN], res[kMaxN];
std::map<int, int> mp;

u64 gethash(int *a) {
  u64 hs = 0;
  for (int i = 1; i <= n; ++i)
    hs = 13331ull * hs + a[i] + 1;
  return hs;
}

int getid(int *a) { return mp[gethash(a)]; }

void check() {
  mp[gethash(now)] = ++cnt;
  for (int i = 1; i <= n; ++i)
    cc[cnt][i] = now[i];
}

void dfs(int x, int sum) {
  if (x == n + 1) {
    if (sum == m) check();
    return;
  }
  for (now[x] = 0; now[x] <= m - sum; ++now[x]) {
    dfs(x + 1, sum + now[x]);
  }
}

void gauss() {
  for (int i = 1; i <= cnt; ++i) {
    if (!w[i][i]) {
      for (int j = i + 1; j <= cnt; ++j) {
        if (w[j][i]) {
          std::swap(i, j);
          break;
        }
      }
    }
    for (int j = i + 1; j <= cnt; ++j) {
      int p = 1ll * w[j][i] * qpow(w[i][i]) % kMod;
      for (int k = i; k <= cnt + 1; ++k)
        w[j][k] = (w[j][k] - 1ll * p * w[i][k] % kMod + kMod) % kMod;
    }
  }
  for (int i = cnt; i; --i) {
    for (int j = i + 1; j <= cnt; ++j)
      w[i][cnt + 1] = (w[i][cnt + 1] - 1ll * res[j] * w[i][j] % kMod + kMod) % kMod;
    res[i] = 1ll * w[i][cnt + 1] * qpow(w[i][i]) % kMod;
  }
}

void solve() {
  dfs(1, 0);
  int p = qpow((n - 1) * m * m);
  for (int i = 1; i <= cnt; ++i) {
    int ct = 0;
    for (int j = 1; j <= n; ++j) {
      now[j] = cc[i][j];
      ct += (bool)now[j];      
    }
    int cur = getid(now);
    w[cur][cur] = 1;
    if (ct != 1) {
      w[cur][cnt + 1] = 1;
      for (int j = 1; j <= n; ++j) {
        for (int k = 1; k <= n; ++k) {
          int pp = 1ll * now[j] * (m - now[k]) % kMod * p % kMod;
          --now[j], ++now[k];          
          int nxt = getid(now);
          w[cur][nxt] = (w[cur][nxt] - pp + kMod) % kMod;
          ++now[j], --now[k];
        }
      }
    }
  }
  gauss();
  for (int cs = 1; cs <= t; ++cs) {
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    std::cout << res[getid(a)] << '\n';
  }
}
} // namespace Sub1

namespace Sub2 {
int f[kMaxM];
std::pair<int, int> g[kMaxM];

void solve() {
  int p = qpow((n - 1) * m * m);
  g[1] = {1, 0};
  for (int i = 1; i < m; ++i) {
    int a = (kMod - 1ll * p * i % kMod * i % kMod) % kMod;
    int b = (1 - 2ll * p * i % kMod * (m - i) % kMod + kMod) % kMod;
    int c = (kMod - 1ll * p * (m - i) % kMod * (m - i) % kMod) % kMod;
    g[i + 1].first = ((kMod - a) * g[i - 1].first % kMod + (kMod - b) * g[i].first % kMod) % kMod * qpow(c) % kMod;
    g[i + 1].second = ((kMod - a) * g[i - 1].second % kMod + (kMod - b) * g[i].second % kMod + 1) % kMod * qpow(c) % kMod;
  }
  f[1] = 1ll * (kMod - g[m].second) * qpow(g[m].first) % kMod;
  for (int i = 2; i <= m; ++i) {
    f[i] = (f[1] * g[i].first + g[i].second) % kMod;
  }
  for (int cs = 1; cs <= t; ++cs) {
    int a, b;
    std::cin >> a >> b;
    std::cout << f[a] << '\n';
  }
}
} // namespace Sub2

void dickdreamer() {
  std::cin >> n >> m >> t;
  if (n <= 5 && m <= 5) Sub1::solve();
  else Sub2::solve();
}

int32_t main() {
  freopen("c.in", "r", stdin);
  freopen("c.out", "w", stdout);
  std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
  int T = 1;
  // std::cin >> T;
  while (T--) dickdreamer();
  // std::cerr << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
  return 0;
}
