#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    vector<int> A(k + 1);
    rep(i, 1, n) A[i % k]++;
    LL ans = 0;
    rep(i, 0, k - 1) if(2 * i % k == 0) 
        ans += 1ll * A[i] * A[i] * A[((k - i) % k + k) % k];
    cout << ans << '\n';
    return 0;
}