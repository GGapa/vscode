#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
#define int long long
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> A(n + 1);
    for(int i = 1, x; i <= m; i++) 
        cin >> x, A[x]++;
    auto check = [&](int x) {
        int ret = 0;
        rep(i ,1, n) {
            if(A[i] <= x) ret += (x - A[i]) / 2;
            else ret += (x - A[i]) ;
        }
        return ret >= 0;
    };
    int l = 1, r = m * 3, ans;
    while(l <= r) {
        int mid = l + r >> 1;
        if(check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}