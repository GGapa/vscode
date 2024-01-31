#include <fstream>
#include <map>
#include <vector>
#define LL long long

using namespace std;

ifstream cin("c.in");
ofstream cout("c.out");

const int kMaxN = 5e3 + 1, kMod = 998244353;
int n, m, k, t, pw[kMaxN], a[kMaxN];
LL d[kMaxN][kMaxN];
map<int, int> q;

LL Pow(LL x, int y = kMod - 2) {
  LL ans = 1;
  for (int i = 1; i <= y; i <<= 1) {
    if (i & y) {
      ans = ans * x % kMod;
    }
    x = x * x % kMod;
  }
  return ans;
}

void Update(LL &x, LL y) { x = (x + y) % kMod; }

void S(int x, int y, int s) {
  if (x == n + 1 && y == m) {
    q[s] = ++k;
    return;
  } else if (x > n || y > m) {
    return;
  }
  for (int i = 0; i <= m; i++) {
    S(x + 1, y + i, s * (m + 1) + i);
  }
}

int W(int x, int y) { return x / pw[y] % (m + 1); }

int main() {
  cin.tie(0), cout.tie(0);
  ios::sync_with_stdio(0);
  cin >> n >> m >> t;
  S(1, 0, 0), k++, pw[0] = 1;
  for (int i = 1; i < n; i++) {
    pw[i] = pw[i - 1] * (m + 1);
  }
  for (int i = 0; i < n; i++) {
    q[pw[i] * m] *= -1;
  }
  for (auto &i : q) {
    if (i.second < 0) {
      i.second *= -1, Update(d[i.second][i.second], 1);
    } else {
      Update(d[i.second][i.second], kMod - 1), Update(d[i.second][k], kMod - 1);
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          int x = W(i.first, j), y = W(i.first, k);
          if (x >= 1 && y < m) {
            Update(d[i.second][abs(q[i.first - pw[j] + pw[k]])], Pow((n - 1) * m * m) * x * (m - y));
          }
        }
      }
    }
  }
  for (int i = 1; i < k; i++) {
    if (!d[i][i]) {
      for (int j = i + 1; j < k; j++) {
        if (d[j][i]) {
          swap(d[i], d[j]);
          break;
        }
      }
    }
    LL inv = Pow(d[i][i]);
    for (int j = i; j <= k; j++) {
      d[i][j] = d[i][j] * inv % kMod;
    }
    for (int j = i + 1; j < k; j++) {
      if (d[j][i]) {
        for (int l = k; l > i; l--) {
          d[j][l] = (d[j][l] - d[j][i] * d[i][l] % kMod + kMod) % kMod;
        }
        d[j][i] = 0;
      }
    }
  }
  for (int i = k - 1; i >= 1; i--) {
    for (int j = i - 1; j >= 1; j--) {
      d[j][k] = (d[j][k] - d[j][i] * d[i][k] % kMod + kMod) % kMod;
      d[j][i] = 0;
    }
  }
  while (t--) {
    int s = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      s = s * (m + 1) + a[i];
    }
    cout << d[q[s]][k] << '\n';
  }
  return 0;
}
