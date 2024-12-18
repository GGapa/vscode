#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define int long long
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    unordered_map<LL, int> cnt;
    for(LL i = 1, ct = 0; i < n; i++) {
        ct += (n - i);  ct -= (i - 1); 
        cnt[ct] += A[i + 1] - A[i] - 1;
    }
    rep(i, 1, n) {
        LL t = 1ll * (i - 1) * (n - i + 1);
        cnt[t + (n - i)] += 1; 
    }
    while(q--) {
        LL x; cin >> x;
        cout << cnt[x] << " ";
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}