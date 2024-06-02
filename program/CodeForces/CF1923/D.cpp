// D
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    rep(i, 1, n) cin >> a[i];

    auto work = [&]() {
        vector<ll> s(n + 1);
        rep(i, 1, n) s[i] = s[i - 1] + a[i];
        vector<int> ans(n + 1, n + 1);
        auto find = [&](int i, int l, int r) {
            while(l < r) {
                int mid = l + r >> 1;
                if(s[mid] - s[i] <= a[i])
                    l = mid + 1;
                else r = mid;
            }
            return (s[l] - s[i] > a[i] ? l : n + 1);
        };
        for(int i = 1, k = 2; i < n; i++) {
            while(k <= n && a[i + 1] == a[k]) k++;
            int r = find(i, i + 1, n);
            r = max(r, k);
            if(r <= n) 
                ans[i] = r - i;
            if(a[i + 1] > a[i]) 
                ans[i] = 1;
        }
        return ans;
    };
    auto ans1 = work();
    reverse(a.begin() + 1, a.end());
    auto ans2 = work();
    rep(i, 1, n) {
        int res = min(ans1[i], ans2[n + 1 - i]);
        if(res > n) res = -1;
        cout << res << " \n"[i == n];
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}