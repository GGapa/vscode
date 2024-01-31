#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int N = 5e3 + 5;
const int M = 1e5 + 5;
const int Mod = 998244353;

inline int qp(int a, int b = Mod - 2) {
  int res = 1;
  while (b) {
    if (b & 1) res = LL(res) * a % Mod;
    a = LL(a) * a % Mod;
    b /= 2;
  }
  return res;
}

int n, m, t;
int a[N];

namespace Sub1 {
int f[M], A[N], B[N];
void init() {
  int iv = qp(LL(m) * m % Mod);
  A[1] = 1;
  for (int i = 1; i < m; ++i) {
    int r1 = LL(m - i) * (m - i) % Mod * iv % Mod;
    int r2 = LL(i) * (i) % Mod * iv % Mod;
    int r3 = (r1 + r2) % Mod;
    A[i + 1] = (LL(A[i]) * r3 % Mod + Mod - LL(r2) * A[i - 1] % Mod) % Mod * qp(r1) % Mod;
    B[i + 1] = (LL(B[i]) * r3 % Mod + (Mod - 1) + (Mod - LL(r2) * B[i - 1] % Mod)) % Mod * qp(r1) % Mod;
  }
  int x = LL(Mod - B[m]) * qp(A[m]) % Mod;
  for (int i = 1; i < m; ++i) {
    f[i] = (LL(A[i]) * x % Mod + B[i]) % Mod;
  }
}
void main() {
  init();
  while (t--) {
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cout << f[a[1]] << "\n";
  }
}
}

int main() {
  freopen("c.in", "r", stdin);
  freopen("c.out", "w", stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> t;
  if (n == 2) Sub1::main();
  return 0;
}