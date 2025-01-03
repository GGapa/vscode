#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    auto work = [&]() {
        std::vector<i64> s(n + 1);
        for (int i = 0; i < n; i++) {
            s[i + 1] = s[i] + a[i];
        }
        
        std::vector<int> ans(n, n + 1);
        for (int i = 0, k = 1; i < n - 1; i++) {
            while (k < n && a[i + 1] == a[k]) {
                k++;
            }
            
            int r = *std::ranges::partition_point(std::ranges::iota_view(i + 2, n + 1),
                [&](int v) {
                    return s[v] - s[i + 1] <= a[i];
                });
            r = std::max(r, k + 1);
            if (r <= n) {
                ans[i] = r - (i + 1);
            }
            if (a[i + 1] > a[i]) {
                ans[i] = 1;
            }
        }
        return ans;
    };
    
    auto ans1 = work();
    std::reverse(a.begin(), a.end());
    auto ans2 = work();
    for (int i = 0; i < n; i++) {
        int res = std::min(ans1[i], ans2[n - 1 - i]);
        if (res > n) {
            res = -1;
        }
        std::cout << res << " \n"[i == n - 1];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}