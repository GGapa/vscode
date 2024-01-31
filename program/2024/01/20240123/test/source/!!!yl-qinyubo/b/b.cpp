#include <bits/stdc++.h>
using namespace std;
namespace QYB {
  using ll = long long; const int P = 1000000007;
  int n1, n2, d1[805], d2[805], p1[805], p2[805], lim[805], f[805][805]; vector<int> g1[805], g2[805];
  vector<pair<int, int> > vec; vector<int> st;
  char getchar() {
    static char buf[1 << 25], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 25, stdin)) == buf? EOF: *p1++;
  } int read() {
    int res = 0; char ch = getchar();
    while (ch < 48 || ch > 57) ch = getchar();
    while (ch >= 48 && ch <= 57) res = res * 10 + ch - 48, ch = getchar();
    return res;
  } void dfs1(int cur) {
    for (int to: g1[cur]) dfs1(to);
    if (g1[cur].size() == 1) {
      d1[cur] = d1[g1[cur][0]] + 1, p1[cur] = p1[g1[cur][0]];
    } else d1[cur] = 1, p1[cur] = cur;
  } void dfs2(int cur) {
    for (int to: g2[cur]) dfs2(to);
    if (g2[cur].size() == 1) {
      d2[cur] = d2[g2[cur][0]] + 1, p2[cur] = p2[g2[cur][0]];
    } else d2[cur] = 1, p2[cur] = cur;
  } bool init(int c1, int c2) {
    if (d1[c1] > d2[c2] || g1[p1[c1]].size() != g2[p2[c2]].size()) return false;
    vec.push_back(make_pair(d1[c1], d2[c2])); c1 = p1[c1]; c2 = p2[c2];
    for (int i = 0; i < g1[c1].size(); i++) {
      if (!init(g1[c1][i], g2[c2][i])) return false;
    } return true;
  } int work() {
    if (st.empty()) return 0; f[0][0] = 1;
    sort(st.begin(), st.end()); ll res = 1;
    for (int i = 1; i <= n1; i++) lim[i] = 0; int minn = st[0];
    for (auto i: vec) if (i.second < i.first * minn) return 0;
    for (auto i: vec) lim[i.first] = max(lim[i.first], i.second);
    for (int i = n1; i >= 1; i--) lim[i] = max(lim[i], lim[i + 1] - minn);
    for (int i = 1; i <= n1; i++) {
      for (int j = i * minn; j <= lim[i]; j++) f[i][j] = 0;
      for (int j = (i - 1) * minn; j <= lim[i - 1] && j <= lim[i] - minn; j++) {
        for (int k: st) {
          if (j + k > lim[i]) break;
          (f[i][j + k] += f[i - 1][j]) %= P;
        }
      }
    } for (auto i: vec) (res *= f[i.first][i.second]) %= P;
    return res;
  } int main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    n1 = read(); n2 = read();
    for (int i = 2; i <= n1; i++) g1[read()].push_back(i);
    for (int i = 2; i <= n2; i++) g2[read()].push_back(i);
    dfs1(1); dfs2(1); int q = read();
    if (!init(1, 1)) { while (q--) printf("0\n"); return 0; }
    while (q--) {
      if (read() == 1) st.push_back(read());
      else st.erase(find(st.begin(), st.end(), read()));
      printf("%d\n", work());
    } cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    return 0;
  }
} int main() { return QYB::main(); }