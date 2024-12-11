#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int mod = 1e9 + 7;

signed main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, tp; cin >> n >> tp;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    sort(A.begin() + 1, A.end());    
    LL ans = 0;
    rep(i, 1, n / 2) ans += -2ll * A[i];
    rep(i, n / 2 + 1 + (n % 2), n) ans += 2ll * A[i];
    cout << ans << " ";
    if(tp == 0) return 0;
    vector<LL> mul(n + 1); mul[0] = 1;
    rep(i, 1, n) mul[i] = mul[i - 1] * i % mod;
    ans = mul[n / 2] * mul[n / 2] % mod * 2 % mod;
    if(n & 1) (ans *= n) %= mod;
    cout << ans << '\n';
    return 0;
}
/*
首先可以推出结论，一定是大小元素交替放置产生的差是最大的。
考虑拆贡献

*/

 