#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define CSP2024 GG BUT I WILL WIN NOIP2024
#define int long long
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int xa, xb, xc, ya, yb, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    LL ans = 0;    
    if((xb - xa) * (xc - xa) >= 0)  {
        ans = ans + min(abs(xb - xa), abs(xc - xa));
    }
    if((yb - ya) * (yc - ya) >= 0)  {
        ans = ans + min(abs(yb - ya), abs(yc - ya));
    }
    cout << ans + 1 << '\n';

} 

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}