#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    LL n; int k, q; cin >> n >> k >> q;
    for(LL x, y; q--; ) {
        cin >> x >> y;
        int ans = 0;
        while(x != y) {
            if(x < y) swap(x, y);
            x = (x + k - 2) / k;
            ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}