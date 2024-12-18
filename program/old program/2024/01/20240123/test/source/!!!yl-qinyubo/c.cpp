#include <bits/stdc++.h>
using namespace std;
namespace QYB {
  int n, m, t, cnt[15]; vector<int> a, b;
  int main() {
    mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++) {
      cin >> cnt[i];
      for (int j = 1; j <= m; j++) {
        (j <= cnt[i]? a: b).push_back(i);
      }
    } while (true) {
      int i = rnd() % a.size(), j = rnd() % b.size();
      int x = a[i], y = b[j]; a.erase(a.begin() + i); b.erase(b.begin() + j);
      a.push_back(y); b.push_back(x); --cnt[x]; ++cnt[y]; int maxn = 0;
      static int tot = 0; printf("%d: ", ++tot);
      for (int i = 1; i <= n; i++) {
        printf("%d%c", cnt[i], " \n"[i == n]); maxn = max(maxn, cnt[i]);
      } if (maxn == m) break;
    } return 0;
  }
} int main() { return QYB::main(); }