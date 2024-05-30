#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    int nw = 0, ans = 0;
    rep(i, 1, n) {
        int x; cin >> x;
        if(nw + x > k) nw = 0, ans++;
        nw += x;

    }
    ans++;
    cout << ans << '\n';
    return 0;
}