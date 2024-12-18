#include <algorithm>
#include <ctime>
#include <iostream>
#include <set>
#include <vector>
#define RF(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)

using namespace std;
using LL = long long;
using Pii = pair<int, int>;
using Pll = pair<LL, LL>;

const int kN = 801, kQ = 101, kM = 1e9 + 7;

int n[2], fa[2][kN], q, mx0, mx1, mnv = 1e9, mxv = 0;
vector<int> e[2][kN];
vector<Pii> l;
set<int> ql;
LL f[kN][kN];

void I(int x0, int x1, int l0, int l1) {
  if (e[0][x0].size() == 1) {
    I(e[0][x0][0], x1, l0 + 1, l1);
    return;
  }
  if (e[1][x1].size() == 1) {
    I(x0, e[1][x1][0], l0, l1 + 1);
    return;
  }
  if (e[0][x0].size() != e[1][x1].size()) {
    for (int i = 1; i <= q; ++i) {
      cout << "0\n";
    }
    exit(0);
  }
  if (l0 > l1) {
    for (int i = 1; i <= q; ++i) {
      cout << "0\n";
    }
    exit(0);
  }
  if (l0 == l1) {
    mnv = 1, mxv = max(mxv, 1);
  } else {
    l.emplace_back(l0, l1);
    mx0 = max(mx0, l0), mx1 = max(mx1, l1);
    mnv = min(mnv, l1 / l0);
    mxv = max(mxv, (l1 + l0 - 1) / l0);
  }
  for (int i = 0; i < e[0][x0].size(); ++i) {
    I(e[0][x0][i], e[1][x1][i], 1, 1);
  }
}

int main() {
  RF("b");
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n[0] >> n[1];
  for (int o = 0; o < 2; ++o) {
    for (int i = 2; i <= n[o]; ++i) {
      cin >> fa[o][i];
      e[o][fa[o][i]].push_back(i);
    }
  }
  cin >> q;
  I(1, 1, 1, 1);
  for (int o, x; q--;) {
    cin >> o >> x;
    if (o == 1) {
      ql.insert(x);
    } else {
      ql.erase(x);
    }
    int mn = *ql.begin(), mx = *ql.rbegin();
    if (mn > mnv || mx < mxv) {
      cout << 0 << '\n';
      continue;
    }
    f[0][0] = 1;
    for (int i = 1; i <= mx0; ++i) {
      for (int j = 1; j <= mx1; ++j) {
        f[i][j] = 0;
        for (auto k = ql.begin(); k != ql.end() && *k <= j - (i - 1) * mn; ++k) {
          f[i][j] += f[i - 1][j - *k];
        }
        f[i][j] %= kM;
      }
    }
    int ans = 1;
    for (Pii i : l) {
      ans = ans * f[i.first][i.second] % kM;
    }
    cout << ans << '\n';
  }
  cerr << clock();
  return 0;
}