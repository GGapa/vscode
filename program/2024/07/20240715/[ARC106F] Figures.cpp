#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;
const int mod = 998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int sum = 0;
    int ans = 1;
    for(int i = 1, x; i <= n; i++)  
        cin >> x, sum += x, (ans *= x) %= mod;
    sum -= n;
    rep(i, 0, n - 3) (ans *= (sum - i) % mod) %= mod;
    cout << ans << '\n';
    return 0;
}