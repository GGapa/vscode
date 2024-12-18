//Factory Machines 
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
#define int long long

int n, t;
int a[N];

ll check(ll x) {
    ll ans = 0;
    rep(i, 1, n) {
        ans += 1ll * x / a[i];
        // if(ans >= t) return ans;
    }
    return ans;

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t;
    rep(i, 1, n) cin >> a[i];
    ll l = 1, r = 1e18 + 10, ans;
    while(l <= r) {
        ll mid = l + r >> 1;   
        ll tmp = check(mid);
        if(tmp >= t) {
            r = mid -1 ;
            ans = mid;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans  << '\n';
    return 0;
}