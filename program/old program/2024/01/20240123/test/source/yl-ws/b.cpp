#include <bits/stdc++.h>
using namespace std;
constexpr int N = 805, M = 105, Mod = 1e9 + 7;
int n1, n2, m;
vector<int> G1[N], G2[N];
vector<int> s;
int son[N][N];
int dp[N][N], vis[N][N];
int dfs(int u1, int u2) {
  if (vis[u1][u2]) {
    return dp[u1][u2];
  }
  if (!u1 || !u2) {
    return 0;
  }
  vis[u1][u2] = 1;
  dp[u1][u2] = 0;
  for (auto o : s) {
    int sum = 1;
    if (!son[u2][o - 1]) {
      continue;
    }
    int nu2 = son[u2][o - 1];
    if (G1[u1].size() != G2[nu2].size()) {
      continue;
    }
    for (int i = 0; i < G1[u1].size(); i++) {
      sum = 1LL * sum * dfs(G1[u1][i], G2[nu2][i]) % Mod;
    }
    dp[u1][u2] = (dp[u1][u2] + sum) % Mod;
  }
  return dp[u1][u2];
}
int main() {
  freopen("b.in", "r", stdin);
  freopen("b.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n1 >> n2;
  for (int i = 2, f; i <= n1; i++) {
    cin >> f;
    G1[f].push_back(i);
  }
  for (int i = 2, f; i <= n2; i++) {
    cin >> f;
    G2[f].push_back(i);
  }
  for (int i = 1; i <= n2; i++) {
    son[i][0] = i;
    for (int j = 1; j <= n2; j++) {
      if (G2[son[i][j - 1]].size() != 1) {
        break;
      }
      son[i][j] = G2[son[i][j - 1]].back();
    }
  }
  cin >> m;
  for (int i = 1, op, x; i <= m; i++) {
    cin >> op >> x;
    if (op == 1) {
      s.push_back(x);
    } else {
      for (int o = 0; o < s.size(); o++) {
        if (s[o] == x) {
          s.erase(s.begin() + o);
          break;
        }
      }
    }
    memset(vis, 0, sizeof vis);
    cout << dfs(1, 1) << '\n';
  }
  cerr << clock();
  return 0;
}