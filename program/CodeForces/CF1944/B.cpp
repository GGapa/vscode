#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

void solve() {
    int n,k; cin >> n >> k;
    vector<int> A(n + 1), B(n + 1);
    rep(i, 1, n) cin >> A[i];
    rep(i, 1, n) cin >> B[i];
    vector<int> sa(n + 1), sb = sa;
    rep(i, 1, n) sa[A[i]]++;
    rep(i, 1, n) sb[B[i]]++;
    
    vector<int> ans;
    int cnt  = 0;
    rep(i, 1, n) if(sa[A[i]] == 1) cnt++, ans.push_back(A[i]);
    int cc = 0;
    for(int i = 1; i <= n && cc + 2 <= k * 2; i++) if(sa[A[i]] == 2) {
        sa[A[i]] = 0;
        cout << A[i] << ' ' << A[i] << ' ';
        cc += 2;
    }
    rep(i, 0, k * 2 - cc - 1) cout << ans[i] << " ";
    cout << '\n';
    cc = 0;
    for(int i = 1; i <= n && cc + 2 <= k * 2; i++) if(sb[B[i]] == 2) {
        sb[B[i]] = 0;
        cout << B[i] << ' ' << B[i] << ' ';
        cc += 2;
    }
    rep(i, 0, k * 2 - cc - 1) cout << ans[i] << " ";
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}