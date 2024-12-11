// 月球疏散行动T6
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1, x; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    int mx = *a.rbegin();
    mx += m;
    vector<int> A(mx + 1), S = A, R = A, F(mx + 1, 1e18);   
    rep(i, 1, n) S[a[i]]++, R[a[i]] += a[i];
    rep(i, 1, mx) S[i] += S[i - 1], R[i] += R[i - 1];
    int ans = 1e18;
    rep(i, 0, m - 1) F[i] = S[i] * i - R[i];
    rep(i, m, mx) {
        
        per(j, i - m, max(1ll * 0, i - 2 * m)) 
            F[i] = min(F[i], F[j] + i * (S[i] - S[j]) - (R[i] - R[j]));
        if(i >= mx - m) ans = min(ans, F[i]);
    }
    cout << ans << '\n';
    return 0;
}