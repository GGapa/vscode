#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> A(n + 10), cnt(n + 10);
    rep(i, 1, n) cin >> A[i];
    rep(i, 1, n) if(A[i] <= n) cnt[A[i]]++;
    for(int i = 0; ; i++) {
        if (!cnt[i])
            return cout << i << "\n", void();
        else if (i + x <= n)
            cnt[i + x] += cnt[i] - 1;
    } 
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}