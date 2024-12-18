#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

#define int long long 

void solve() {
    ll k, x; cin >> k >> x;
    if(k == 1) return cout << 1 << '\n', void();
    if((1 + k) * k / 2 >= x) {
        int l = 1, r = k, ans = -1;
        while(l <= r) {
            int mid = l + r >> 1;
            int t = (1 + mid) * mid / 2;
            if(t < x) l = mid + 1;
            else if(t >= x) r = mid - 1, ans = mid;
        }
        if(ans == -1) ans = k;
        cout << ans << '\n';
    }
    else {
        int l = 1, r = k - 1, ans = -1;
        x -= (1 + k) * k / 2;
        while(l <= r) {
            int mid = l + r >> 1;
            int t = (k - 1 + k - 1 - mid + 1) * mid / 2;
            if(t < x) l = mid + 1;
            else if(t >= x) r = mid - 1, ans = mid;
        }
        if(ans == -1) ans = k - 1;
        cout << k + ans << '\n', void();
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}