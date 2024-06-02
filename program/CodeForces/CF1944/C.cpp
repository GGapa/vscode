#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    unordered_map<int, int> mp;
    for(int i = 1, x; i <= n; i++) cin >> x, mp[x]++;
    int mex = -1, cn = 0;
    rep(i, 0, n) {
        if(mp[i] == 0) {
            mex = i;
            break;
        }
        if(mp[i] == 1) {
            if(cn == 1) {
                mex = i;
                break;
            }
            cn++;
        }
    }
    cout << mex << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}