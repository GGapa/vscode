#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define CSP2024 GG BUT I WILL WIN NOIP2024
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, k; cin >> n >> k;
    if(n == 1) return cout << 1 << '\n' << 1 << '\n', void();
    int m1 = k - 1, m2 = n - k;
    int l = 0;
    if(m1 % 2 != m2 % 2) return cout << -1 << '\n', void();
    if(m1 % 2 == 0) l = 1;
    if(1 > k - l || k + 1 + l > n) return cout << -1 << '\n', void();
    cout << 3 << '\n';
    cout << 1 << " " << k - l << " " <<  k + 1 + l << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}