#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n = 1e5;
    vector<int> a;
    cout << n << '\n';
    rep(i, 1, n) a.emplace_back(rand() % (int)5e5);
    sort(a.begin(), a.end());
    for(auto A : a) cout << A << ' ';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    freopen("test.in", "w", stdout);
    cout << T << '\n';
    while(T--) solve();
    return 0;
}