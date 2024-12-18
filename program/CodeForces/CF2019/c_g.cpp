#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; LL k; cin >> n >> k;
    vector<LL> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    LL mx = *max_element(A.begin(), A.end());
    LL sum = accumulate(A.begin() + 1, A.end(), 0LL);


    per(i, n, 1) {
        LL now = mx * i;
        now = max(now, sum + (i - sum % i) % i);
        if(now - sum <= k) return cout << i << '\n', void();
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}