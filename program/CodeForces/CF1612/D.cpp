#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

ll x;

bool dfs(ll a, ll b) {
    if(a < b) swap(a, b);
    if(a == 0 || b == 0 || a < x) return 0;
    if(a == x || b == x || (a - x) % b == 0) return 1;
    return dfs(a % b, b);
}

ll a, b;

void solve() {
    cin >> a >> b >> x;
    if(dfs(a, b)) return cout << "YES\n", void();
    cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}