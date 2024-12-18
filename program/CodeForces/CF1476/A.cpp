#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;

void solve() {
    int n, k; cin >> n >> k;
    int v = k * ((n / k) + (n % k != 0));
    int l = 1, r = 1e9;
    while(l <= r) {
        int mid = l + r >> 1;
        if(n * mid >= v) r = mid - 1;
        else l = mid + 1;
    }
    cout << l << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}