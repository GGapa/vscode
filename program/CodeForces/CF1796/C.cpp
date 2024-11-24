#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int mod = 998244353;

void solve() {
    int l, r; cin >> l >> r;
    int n = 0;
    for(int i = l; i <= r; i *= 2) n++;  
    cout << n << " ";
    LL cnt = r / (1 << n - 1) - l + 1, ct2 = r / (3 * (1 << n - 2)) - l + 1;
    // for(int i = l; i * (1 << n - 2) * 3 <= r; i++) ct2++;
    if(ct2 > 0)   (cnt += ct2 * (n - 1) % mod) %= mod;
    cout << cnt << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}