//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;

void solve() {
    int n; cin >> n; 
    vector<VI> A(n + 1); 
    vector<int> X(n + 1);
    rep(i, 1, n) cin >> X[i];
    vector<int> ans(n + 1);
    for(int i = 1, x; i <= n; i++) {
        cin >> x, A[X[i]].emplace_back(x);
    }
    rep(i, 1, n) if(!A[i].empty()){
        int m = A[i].size();
        sort(A[i].begin(), A[i].end(), greater<>());
        vector<int> sum(m + 2);
        sum[m - 1] = A[i][m- 1];
        per(j, m - 2, 0) sum[j] = sum[j + 1] + A[i][j];
        rep(j, 1, m) ans[j] += sum[0] - sum[m - (m % j)];
        // rep(j, 1, n) cout << ans[j] << " \n"[j == n];
    }
    rep(i, 1, n) cout << ans[i] << " \n"[i == n];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}