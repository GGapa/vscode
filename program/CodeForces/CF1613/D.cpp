#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

const int mod = 998244353;

void solve() {
    int n; cin >> n;
    vector<ll> F(n + 2), G(n + 2);
    ll ans = 0;
    F[0] = 1;
    for(int i = 1, x; i <= n; i++) {
        cin >> x;
        (ans += F[x + 1] + F[x] + G[x + 1]) %= mod;
        if(x) (ans += G[x - 1] + F[x - 1]) %= mod;

        (F[x + 1] += F[x + 1] + F[x]) %= mod;
        (G[x + 1] += G[x + 1]) %= mod;
        if(x) (G[x - 1] += G[x - 1] + F[x - 1]) %= mod;

    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
/*
1
5
0 1 0 1 2
*/