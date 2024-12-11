# include <bits/stdc++.h>
# define ll long long

using namespace std;

vector<pair<int, int> > query;

const ll mod = 1e9 + 7;
const int N = 805;
int q, o, x, m1, m2, fl = 1;

struct T {
vector<int> son[N];
int n;
void in() {
  for (int i = 2, u; i <= n; i++) {
    cin >> u;
    son[u].push_back(i);
  }
}
} T1, T2;

void dfs(int x1, int x2) {
  int len1 = 1, len2 = 1;
  # define s1 T1.son[x1]
  # define s2 T2.son[x2]
  while (s1.size() == 1) {
    ++len1;
    x1 = s1[0];
  }
  while (s2.size() == 1) {
    ++len2;
    x2 = s2[0];
  }
  query.emplace_back(len1, len2);
  m1 = max(m1, len1);
  m2 = max(m2, len2);
  if (s1.size() != s2.size()) {
    fl = 0;
    return;
  }
  for (int i = 0; i < s1.size() && fl; i++) {
    dfs(s1[i], s2[i]);
  }
  # undef s1
  # undef s2
}

struct Arr {
ll f[N];
Arr(int x = 0) {
  memset(f, 0, sizeof(ll) * (m2 + 1));
  f[0] = x;
}
} v;

Arr operator * (Arr &f, Arr v) {
  Arr res;
  for (int i = 0; i <= m2; i++) {
    if (f.f[i]) {
      for (int j = 0; i + j <= m2; j++) {
        (res.f[i + j] += f.f[i] * v.f[j]) %= mod;
      }
    }
  }
  return res;
}

Arr qp(Arr x, int y) {
  Arr res = Arr(1);
  while (y) {
    if (y & 1) {
      res = res * x;
    }
    x = x * x;
    y >>= 1;
  }
  return res;
}

Arr f;
ll clc() {
  f = Arr(1);
  int now = 0;
  ll res = 1;
  for (auto i : query) {
    if (i.first > now) {
      f = f * qp(v, i.first - now);
    }
    now = i.first;
    (res *= f.f[i.second]) %= mod;
  }
  return res;
}

int main() {
  // freopen("ex_b3.in", "r", stdin);
  // freopen("ex_b3.out", "w", stdout);
  freopen("b.in", "r", stdin);
  freopen("b.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  cin >> T1.n >> T2.n;
  T1.in(); T2.in();
  cin >> q;
  dfs(1, 1);
  if (!fl) {
    while (q--) {
      cout << 0 << '\n';
    }
    return 0;
  }
  sort(query.begin(), query.end());
  while (q--) {
    cin >> o >> x;
    if (o == 1) {
      v.f[x] = 1;
    } else {
      v.f[x] = 0;
    }
    cout << clc() << '\n';
  }
  // cerr << clock();
}