#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int m = 1 << n; int x = 0; 
    for(auto c : s) if(c == '1') x++;
    rep(i, 1 << x, (1 << n) - (1 << n - x) + 1) cout << i << " ";
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T--) solve();
    return 0;
}