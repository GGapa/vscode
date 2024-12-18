#include<bits/stdc++.h>
#define ll long long
#define db double
#define ull unsigned long long
#define pb push_back
#define pii pair<int, int>
#define FR first
#define SE second
#define il inline
using namespace std;
inline int read() {
  int x = 0; bool op = false;
  char c = getchar();
  while(!isdigit(c))op |= (c == '-'), c = getchar();
  while(isdigit(c))x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return op ? -x : x;
}
const int N = 1e3 + 10;
const int P = 1e9 + 7;
il void add(int &a, int b) {a += b; a >= P ? a -= P : 0;}
il void sub(int &a, int b) {a -= b; a < 0 ? a += P : 0;}
il int ksm(int x, int k) {
  int res = 1;
  for(int pw = x; k; (k & 1) ? res = 1ll * res * pw % P : 0, pw = 1ll * pw * pw % P, k >>= 1);
  return res;
}
int fac[N], ifac[N];
il void init() {
  fac[0] = ifac[0] = 1;
  for(int i = 1; i < N; i++)fac[i] = 1ll * fac[i - 1] * i % P;
  ifac[N - 1] = ksm(fac[N - 1], P - 2);
  for(int i = N - 2; i; i--)ifac[i] = 1ll * ifac[i + 1] * (i + 1) % P;
  return ;
}
int com(int n, int m) {return n < m || m < 0 ? 0 : 1ll * fac[n] * ifac[m] % P * ifac[n - m] % P;}
int B = 20;
int n1, n2, Q;
int val1[N][N], val2[N][N], vis[N][N], f[N][N];
int nxt1[N], nxt2[N], dep1[N], dep2[N];
vector<int> G1[N], G2[N];
void dfs1(int u) {
  for(int v : G1[u])dep1[v] = dep1[u] + 1, dfs1(v);
  if(G1[u].size() != 1)nxt1[u] = u;
  else nxt1[u] = nxt1[G1[u][0]];
  return ;
}
void dfs2(int u) {
  for(int v : G2[u])dep2[v] = dep2[u] + 1, dfs2(v);
  if(G2[u].size() != 1)nxt2[u] = u;
  else nxt2[u] = nxt2[G2[u][0]];
  return ;
}
void pre(vector<int> S) {
  for(int i = 0; i <= n1; i++) {
    for(int j = 0; j <= n2; j++) {
      val1[i][j] = val2[i][j] = 0;
      vis[i][j] = f[i][j] = 0;
    }
  }
  vector<int> S1, S2;
  for(int x : S)(x <= B ? S1 : S2).pb(x);
  val1[0][0] = val2[0][0] = 1;
  for(int i = 0; i < n1; i++) {
    for(int j = 0; j <= n2; j++) {
      if(val1[i][j]) {
        for(int x : S1)if(j + x <= n2)
          add(val1[i + 1][j + x], val1[i][j]);
      }
      if(val2[i][j]) {
        for(int x : S2)if(j + x <= n2)
          add(val2[i + 1][j + x], val2[i][j]);
      }
    }
  }
  return ;
}
int qval(int len1, int len2) {
  int res = 0;
  for(int j = 0; j <= len2; j++) {
    for(int i = 0; i <= min(len1, j / B); i++) {
      if(!val1[len1 - i][len2 - j] || !val2[i][j])continue;
      add(res, 1ll * val1[len1 - i][len2 - j] * val2[i][j] % P * com(len1, i) % P);
    }
  }
  return res;
}
int dfs(int x, int y) {
  if(vis[x][y])return f[x][y];
  vis[x][y] = true;
  int nx = nxt1[x], ny = nxt2[y];
  if(G1[nx].size() != G2[ny].size())return f[x][y] = 0;
  int lim = G1[nx].size(); f[x][y] = 1;
  for(int i = 0; i < lim; i++)f[x][y] = 1ll * f[x][y] * dfs(G1[nx][i], G2[ny][i]) % P;
  int len1 = dep1[nx] - dep1[x] + 1, len2 = dep2[ny] - dep2[y] + 1;
  f[x][y] = 1ll * f[x][y] * qval(len1, len2) % P;
  return f[x][y];
}
int main() {
  freopen("b.in", "r", stdin);
  freopen("b.out", "w", stdout);
  init();
  n1 = read(); n2 = read();
  for(int i = 2; i <= n1; i++) {int u = read(); G1[u].pb(i);}
  for(int i = 2; i <= n2; i++) {int u = read(); G2[u].pb(i);}
  dfs1(1); dfs2(1);
  Q = read();
  vector<int> S;
  for(int _ = 1; _ <= Q; _++) {
    int op = read(), x = read();
    // cerr << op << ' ' << x  << endl;
    // int op = 1, x = _ * 2;
    if(op == 1)S.pb(x);
    else S.erase(find(S.begin(), S.end(), x));
    pre(S);
    printf("%d\n", dfs(1, 1));
  }
  return 0;
}