#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> L(n + 1), R(n + 1), len(n + 1);
    rep(i ,1, n) cin >> L[i] >> R[i], len[i] = R[i] - L[i] + 1;
    int ans = 0;
    int ml = 0, mr = m;
    ml = *max_element(L.begin() + 1, L.end());
    mr = *min_element(R.begin() + 1, R.end());
    ans = max(ans, *max_element(len.begin(), len.end()) - *min_element(len.begin() + 1, len.end()));
    rep(i, 1, n) ans = max(ans, min(len[i], max(ml - L[i], R[i] - mr))) ;
    cout << ans * 2 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
/*
可以将题目转化为选定两个区间
*/