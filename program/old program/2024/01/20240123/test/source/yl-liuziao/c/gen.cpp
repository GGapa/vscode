#include <bits/stdc++.h>

// #define int int64_t

void dickdreamer() {
  int m = 1e5;
  std::cout << 2 << ' ' << m << ' ' << m + 1 << '\n';
  for (int i = 0; i <= m; ++i)
    std::cout << i << ' ' << m - i << '\n';
}

int32_t main() {
  freopen("c.in", "w", stdout);
  std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
  int T = 1;
  // std::cin >> T;
  while (T--) dickdreamer();
  // std::cerr << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
  return 0;
}

