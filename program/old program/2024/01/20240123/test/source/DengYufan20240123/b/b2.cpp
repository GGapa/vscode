#include <algorithm>
#include <ctime>
#include <fstream>
#include <vector>
#define LL long long

using namespace std;

ifstream cin("b.in");
ofstream cout("b.out");

const int kMaxN = 801, kMod = 1e9 + 7;
struct V {
  int l, p;
  vector<int> e;
} v[2][kMaxN];
int n, m, q;
LL ans, c[kMaxN], f[kMaxN], g[kMaxN];
vector<pair<int, int>> t;

void S(int x, bool o) {
  for (int i : v[o][x].e) {
    S(i, o);
  }
  if (v[o][x].e.size() == 1) {
    v[o][x].l = v[o][v[o][x].e[0]].l + 1;
    v[o][x].p = v[o][v[o][x].e[0]].p;
  } else {
    v[o][x].l = 1, v[o][x].p = x;
  }
}

void T(int x, int y) {
  t.push_back({v[0][x].l, v[1][y].l});
  x = v[0][x].p, y = v[1][y].p;
  if (v[0][x].l <= v[1][y].l && v[0][x].e.size() == v[1][y].e.size()) {
    for (int i = 0; i < v[0][x].e.size(); i++) {
      T(v[0][x].e[i], v[1][y].e[i]);
    }
  } else {
    for (int i = 1; i <= q; i++) {
      cout << 0 << '\n';
    }
    exit(0);
  }
}

void Mul(LL f[kMaxN], LL g[kMaxN]) {
  LL ans[kMaxN];
  for (int i = 0; i <= m; i++) {
    ans[i] = 0;
    for (int j = 0; j <= i; j++) {
      ans[i] = (ans[i] + f[j] * g[i - j]) % kMod;
    }
  }
  copy(&ans[0], &ans[m] + 1, &f[0]);
}

int main() {
  cin.tie(0), cout.tie(0);
  ios::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 2, x; i <= n; i++) {
    cin >> x;
    v[0][x].e.push_back(i);
  }
  for (int i = 2, x; i <= m; i++) {
    cin >> x;
    v[1][x].e.push_back(i);
  }
  cin >> q;
  S(1, 0), S(1, 1), T(1, 1), m = 0;
  sort(t.begin(), t.end());
  for (auto j : t) {
    m = max(m, j.second);
  }
  for (int i = 1, o, x, p; i <= q; i++) {
    cin >> o >> x;
    o == 1 ? c[x]++ : c[x]--;
    fill(&f[1], &f[m] + 1, 0);
    ans = f[0] = 1, p = 0;
    for (auto j : t) {
      if (j.first != p) {
        copy(&c[0], &c[m] + 1, &g[0]);
        for (int i = 1; i <= j.first - p; i <<= 1) {
          if (i & j.first - p) {
            Mul(f, g);
          }
          Mul(g, g);
        }
      }
      p = j.first, ans = ans * f[j.second] % kMod;
    }
    cout << ans << '\n';
  }
  // cout << clock() << '\n';
  return 0;
}
