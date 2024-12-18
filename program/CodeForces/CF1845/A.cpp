#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define CSP2024 GG BUT I WILL WIN NOIP2024
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, k, x; cin >> n >> k >> x;
    vector<int> F(n + 1);
    F[0] = 1;
    rep(i, 1, k) if(i != x) {
        rep(j, i, n) F[j] |= F[j - i];
    }
    cout << (F[n] ? "YES" : "NO") << '\n';
    if(F[n] == 0) return;
    vector<int> ans;
    int lt = n;
    per(i, n - 1, 0) if(lt - i != x && F[i] == 1) ans.emplace_back(lt - i), lt = i;
    cout << ans.size() << '\n';
    for(auto a : ans) cout << a << ' ';
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}