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
const int P = 998244353;
const int N = 1e5 + 10;
void add(int &a, int b) {a += b; a >= P ? a -= P : 0;}
void sub(int &a, int b) {a -= b; a < 0 ? a += P : 0;}
int ksm(int x, int k) {
  int res = 1;
  for(int pw = x; k; (k & 1) ? res = 1ll * res * pw % P : 0, pw = 1ll * pw * pw % P, k >>= 1);
  return res;
}
int n, m;
int f[N];
int main() {
  freopen("c.in", "r", stdin);
  freopen("c.out", "w", stdout);
  n = read(); m = read(); int test = read();
  int all = 1ll * m * (n - 1) % P * m % P;
  int iall = ksm(all, P - 2), in = ksm(n, P - 2);
  for(int i = 0; i <= m; i++) {
    int x = i, y = m - x;
    int z = m - i, w = (1ll * (n - 1) * m - z) % P;
    int X = 1ll * x * w % P, Y = (1ll * x * z % P + 1ll * y * w % P) % P, Z = 1ll * y * z % P, lhs = in;
    X = 1ll * iall * X % P; Y = 1ll * iall * Y % P; Z = 1ll * iall * Z % P;
    if(i)sub(lhs, 1ll * X * f[i - 1] % P);
    add(lhs, 1ll * (P + 1 - Y) * f[i] % P);
    f[i + 1] = 1ll * ksm(Z, P - 2) * lhs % P;
  }
  while(test--) {
    int ans = f[m];
    for(int i = 1; i <= n; i++)sub(ans, f[read()]);
    printf("%d\n", ans);
  }
  return 0;
}