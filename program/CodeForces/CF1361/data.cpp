#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n = 3;
    cout << n << " " << rand() % 1000 + 1 << '\n';
    rep(i, 1, n) cout << rand() % 1000<< " \n"[i == n];
}

signed main() {
    freopen("data.in", "w", stdout);
    srand(time(0));
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 10;
    cout << T << '\n';
    while(T--) solve();
    return 0;
}