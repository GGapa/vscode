#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
#define int long long
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> A(n + 1), B(n + 1);
    rep(i, 1, n - 1) cin >> A[i];
    rep(i, 1, n) cin >> B[i];
    sort(A.begin() + 1, A.begin() + n);
    sort(B.begin() + 1, B.begin() + 1 + n);
    int it1 = 1, it2 = 1, mx = 0;
    for(; it1 < n && it2 <= n; it1++, it2++) {
        for(; it2 <= n && A[it1] >= B[it2]; ) mx = B[it2], it2++;
        if(it2 > n) break;
    }
    if(it2 == n) mx = B[n];
    int t = (n - 1) - it1 + 1;
    cout << t * m + max(m - mx + 1, 0ll) << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}