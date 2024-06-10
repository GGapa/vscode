//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> pos(51, INT_MAX);
    for(int i = 1, x; i <= n; i++) 
        cin >> x, pos[x] = min(pos[x], i);
    for(int o = 1, x; o <= q; o++) {
        cin >> x;
        cout << pos[x] << " \n"[o == q];
        rep(i, 1, 50) if(pos[i] < pos[x]) pos[i]++;
        pos[x] = 1;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int T; cin >> T;
    solve();
    return 0;
}