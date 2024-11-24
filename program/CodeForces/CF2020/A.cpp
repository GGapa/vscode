#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, k; cin >> n >> k;
    if(k == 1) return cout << n << '\n', void();
    int  cnt = 0;
    while(n >= k) {
        int t = 1;
        while(1ll * t * k <= n) t *= k;
        n -= t;
        cnt++;
    }
    cout << cnt + n << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}