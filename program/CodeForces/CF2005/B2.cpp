#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, m, q; cin >> n >> m >> q;
    vector<int> B(m + 1);
    rep(i, 1, m) cin >> B[i];
    sort(B.begin() + 1, B.end());
    for(int x; q--; ) {
        cin >> x;
        int r = lower_bound(B.begin() + 1, B.end(), x) - B.begin();
        int l = r - 1;
        if(l == 0) cout << B[r] - 1 << '\n';
        else if(r == m + 1) cout << n - B[l] << '\n';
        else cout << (B[r] - B[l]) / 2 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
/*
1
8 1 1
6
7
*/