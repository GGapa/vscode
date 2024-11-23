#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, m, v; cin >> n >> m >> v;
    vector<int> A(n + 1), suf(n + 2), pre(n + 1);
    vector<LL> S(n + 2);
    rep(i, 1, n) cin >> A[i], S[i] = S[i - 1] + A[i];
    S[n + 1] = S[n];
    for(int i = 1, lt = 0; i <= n; i++) {
        pre[i] = pre[i - 1];
        if(S[i] - S[lt] >= v) {
            pre[i] = max(pre[lt] + 1, pre[i]);
            lt = i; 
        }
    }
    for(int i = n, lt = n + 1; i >= 1; i--) {
        suf[i] = suf[i + 1];
        if(S[lt - 1] - S[i - 1] >= v) {
            suf[i] = max(suf[i], suf[lt] + 1);
            lt = i;
        }
    }
    if(pre[n] < m) return cout << -1 << '\n', void();
    LL ans = 0;
    for(int i = 1, j = 1; i <= n; i++) {
        while(j <= n && suf[j + 1] + pre[i - 1] >= m) j++;
        ans = max(ans, S[j - 1] - S[i - 1]);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}