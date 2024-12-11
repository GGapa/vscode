#include<bits/stdc++.h>
#define ll long long
#define db double
#define ull unsigned long long
#define pb push_back
#define pii pair<int, int>
#define FR first
#define SE second
using namespace std;
inline int read() {
  int x = 0; bool op = false;
  char c = getchar();
  while(!isdigit(c))op |= (c == '-'), c = getchar();
  while(isdigit(c))x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return op ? -x : x;
}
const int N = 1e3 + 10;
const int P = 998244353;
void add(int &a, int b) {a += b; a >= P ? a -= P : 0;}
void sub(int &a, int b) {a -= b; a < 0 ? a += P : 0;}
int ksm(int x, int k) {
  int res = 1;
  for(int pw = x; k; (k & 1) ? res = 1ll * res * pw % P : 0, pw = 1ll * pw * pw % P, k >>= 1);
  return res;
}
int fac[N], ifac[N];
void init() {
  fac[0] = ifac[0] = 1;
  for(int i = 1; i < N; i++)fac[i] = 1ll * fac[i - 1] * i % P;
  ifac[N - 1] = ksm(fac[N - 1], P - 2);
  for(int i = N - 2; i; i--)ifac[i] = 1ll * ifac[i + 1] * (i + 1) % P;
  return ;
}
int com(int n, int m) {return n < m || m < 0 ? 0 : 1ll * fac[n] * ifac[m] % P * ifac[n - m] % P;}
int n, m, k, p, val;
int a[N];
struct Node {
  int f[35];
  void init() {
    for(int i = 0; i <= k; i++)f[i] = 0;
    return ;
  }
};
struct Edge {int u, v, w;};
vector<Edge> E;
Node operator + (Node x, Node y) {
  Node z;
  for(int i = 0; i <= k; i++)z.f[i] = (x.f[i] + y.f[i]) % P;
  return z;
}
Node operator * (Node x, Node y) {
  Node z; z.init();
  for(int i = 0; i <= k; i++) {
    for(int j = 0; i + j <= k; j++) {
      add(z.f[i + j], 1ll * x.f[i] * y.f[j] % P * com(i + j, j) % P);
    }
  }
  return z;
}
Node operator * (Node x, int y) {
  Node z; z.init();
  for(int i = 0, g = 1; i <= k; i++, g = 1ll * g * y % P) {
    for(int j = 0; i + j <= k; j++) {
      add(z.f[i + j], 1ll * g * x.f[j] % P * com(i + j, j) % P);
    }
  }
  return z;
}
namespace S1 {
  vector<pii> G[N];
  Node f[N][35][2], tmp[35][2];
  void dfs(int u, int fa) {
    for(int i = 0; i <= p; i++) {
      f[u][i][0].init();
      f[u][i][1].init();
    }
    f[u][0][0].f[0] = 1;
    f[u][0][1].f[0] = 1;
    f[u][1][1].f[0] = 1;
    f[u][1][0].f[0] = 1;
    f[u][0][1] = f[u][0][1] * a[u];
    f[u][1][1] = f[u][1][1] * ((a[u] + val) % P);
    for(auto t : G[u]) {
      int v = t.FR, w = t.SE;
      if(v == fa)continue;
      dfs(v, u);
      for(int i = 0; i <= p; i++) {
        for(int x = 0; x < 2; x++) {
          tmp[i][x] = f[u][i][x];
          f[u][i][x].init();
        }
      }
      for(int i = 0; i <= p; i++)for(int j = 0; i + j <= p; j++) {
        for(int x = 0; x < 2; x++)for(int y = 0; x + y < 2; y++) {
          Node now = tmp[i][x] * f[v][j][y];
          if(x || y) {
            f[u][i + j][x] = f[u][i + j][x] + now;
            f[u][i + j + 1][x] = f[u][i + j + 1][x] + now;
          }
          else {
            f[u][i + j][x] = f[u][i + j][x] + (now * w);
            f[u][i + j + 1][x] = f[u][i + j + 1][x] + (now * ((w + val) % P));
          }
        }
      }
    }
    return ;
  }
  void MAIN() {
    for(auto t : E) {
      G[t.u].pb({t.v, t.w});
      G[t.v].pb({t.u, t.w});
    }
    dfs(1, 0);
    int ans = (f[1][p][0] + f[1][p][1]).f[k];
    // cout << ans << endl;
    ans = 1ll * ans * ksm(com(n + m, p), P - 2) % P;
    printf("%d\n", ans);
    return ;
  }
};
namespace bf {
  void MAIN() {
    int ans = 0;
    for(int i = 0; i < (1 << n); i++) {
      vector<int> q(n + m);
      for(int j = n + m - p; j < n + m; j++)q[j] = 1;
      do {
        int res = 0, flg = 1;
        for(int j = 0; j < n; j++) {
          int now = q[j] ? (a[j + 1] + val) % P : a[j + 1];
          if(i >> j & 1)add(res, now);
        }
        for(int j = 0; j < m; j++) {
          auto t = E[j];
          int now = q[j + n] ? (t.w + val) % P : t.w;
          if((~i >> (t.u - 1) & 1) && (~i >> (t.v - 1) & 1))add(res, now);
          if((i >> (t.u - 1) & 1) && (i >> (t.v - 1) & 1))flg = 0;
        }
        // if(flg)cout << i << ' ' << res << ' ' << ans << ' ' << k << endl;
        if(flg)add(ans, ksm(res, k));
      }while(next_permutation(q.begin(), q.end()));
    }
    // cout << ans << endl;
    ans = 1ll * ans * ksm(com(n + m, p), P - 2) % P;
    printf("%d\n", ans);
    return ;
  }
};
int main() {
  freopen("d.in", "r", stdin);
  freopen("std.out", "w", stdout);
  init();
  n = read(); m = read(); k = read(); p = read(); val = read();
  for(int i = 1; i <= n; i++)a[i] = read();
  for(int i = 1; i <= m; i++) {
    int u = read(), v = read(), w = read();
    E.pb({u, v, w});
  }
  if(n <= 6)return bf::MAIN(), 0;
  // return S1::MAIN(), 0;
  return 0;
}